#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ar.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef u_int16_t (*rh_t)(u_int16_t *);
typedef u_int32_t (*rw_t)(u_int32_t *);

static u_int32_t read_word_le(u_int32_t *value)
{
  unsigned char *p = (unsigned char *)value;
  return (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24));
}

static u_int32_t read_word_be(u_int32_t *value)
{
  unsigned char *p = (unsigned char *)value;
  return (p[0] << 24 | (p[1] << 16) | (p[2] << 8) | p[3]);
}

static u_int16_t read_half_le(u_int16_t *value)
{
  unsigned char *p = (unsigned char *)value;
  return (p[0] | (p[1] << 8));
}

static u_int16_t read_half_be(u_int16_t *value)
{
  unsigned char *p = (unsigned char *)value;
  return ((p[0] << 8) | p[1]);
}

struct name_list {
  struct name_list *next;
  char *name;
  int size;
  unsigned int flags;
#define NAME_FLAG_NOALLOC (1 << 0)
  char *filename;
  int count;
  int define;
};

static struct name_list *sym_name_list = NULL;
static struct name_list *rel_name_list = NULL;

/* セクション名からセクションヘッダを検索 */
static Elf32_Shdr *get_section(char *filename, rh_t rh, rw_t rw,
			       Elf32_Ehdr *ehdr, char *name)
{
  int i, shnum, shoff, shentsize, nshoff;
  char *head;
  Elf32_Shdr *shdr;
  Elf32_Shdr *nhdr;

  head = (char *)ehdr;
  shnum     = rh(&ehdr->e_shnum);
  shoff     = rw(&ehdr->e_shoff);
  shentsize = rh(&ehdr->e_shentsize);

  nhdr = (Elf32_Shdr *)(head + shoff + shentsize * rh(&ehdr->e_shstrndx));
  nshoff = rw(&nhdr->sh_offset);

  for (i = 0; i < shnum; i++) {
    shdr = (Elf32_Shdr *)(head + shoff + shentsize * i);
    if (!strcmp((char *)(head + nshoff + rw(&shdr->sh_name)), name)) {
      fprintf(stderr, "found %s (%s)\n", name, filename);
      return (shdr);
    }
  }

  fprintf(stderr, "Cannot find %s (%s)\n", name, filename);
  return (NULL);
}

/* シンボルテーブルを総なめして，シンボル名のリストを作成 */
static int make_symbol_table(char *filename, rh_t rh, rw_t rw,
			     Elf32_Ehdr *ehdr, Elf32_Shdr *symtab,
			     Elf32_Shdr *strtab)
{
  int i, shsize, shentsize, shoff, strshoff;
  char *head;
  Elf32_Sym *symp;
  struct name_list *name;

  head = (char *)ehdr;
  if (rw(&symtab->sh_type) != SHT_SYMTAB) {
    fprintf(stderr, "Invalid type. (%d)\n", rw(&symtab->sh_type));
    exit (1);
  }
  if (rw(&symtab->sh_entsize) != sizeof(Elf32_Sym)) {
    fprintf(stderr, "Invalid entry size. (%d)\n", rw(&symtab->sh_entsize));
    exit (1);
  }

  shsize    = rw(&symtab->sh_size);
  shentsize = rw(&symtab->sh_entsize);
  shoff     = rw(&symtab->sh_offset);
  strshoff  = rw(&strtab->sh_offset);

  for (i = 0; i < shsize; i += shentsize) {
    symp = (Elf32_Sym *)(head + shoff + i);
    if (!symp->st_name) continue;
    if (ELF32_ST_BIND(symp->st_info) != STB_GLOBAL) continue;
    if ((ELF32_ST_TYPE(symp->st_info) != STT_NOTYPE) &&
	(ELF32_ST_TYPE(symp->st_info) != STT_OBJECT) &&
	(ELF32_ST_TYPE(symp->st_info) != STT_FUNC))
      continue;
    if (!symp->st_size) continue;

    name = malloc(sizeof(*name));
    name->next = sym_name_list;
    name->name = strdup(head + strshoff + rw(&symp->st_name));
    name->size = rw(&symp->st_size);
    name->flags = 0;
    if (rh(&symp->st_shndx) == SHN_COMMON)
      name->flags |= NAME_FLAG_NOALLOC;
    name->filename = strdup(filename);
    name->count = 0;
    name->define = 1;
    sym_name_list = name;
  }

  return (0);
}

/* 再配置テーブルを総なめして，シンボル名のリストを作成 */
static int make_reltxt_table(char *filename, rh_t rh, rw_t rw,
			     Elf32_Ehdr *ehdr, Elf32_Shdr *reltxt,
			     Elf32_Shdr *symtab, Elf32_Shdr *strtab)
{
  int i, shsize, shentsize, shoff, symshoff, symshentsize, strshoff;
  char *head;
  Elf32_Sym *symp;
  Elf32_Rel *relp;
  struct name_list *name;

  head = (char *)ehdr;
  if ((rw(&reltxt->sh_type) != SHT_REL) &&
      (rw(&reltxt->sh_type) != SHT_RELA)) {
    fprintf(stderr, "Invalid type. (%d)\n", rw(&reltxt->sh_type));
    exit (1);
  }

  shsize       = rw(&reltxt->sh_size);
  shentsize    = rw(&reltxt->sh_entsize);
  shoff        = rw(&reltxt->sh_offset);
  symshoff     = rw(&symtab->sh_offset);
  symshentsize = rw(&symtab->sh_entsize);
  strshoff     = rw(&strtab->sh_offset);

  for (i = 0; i < shsize; i += shentsize) {
    relp = (Elf32_Rel *)(head + shoff + i);
    symp = (Elf32_Sym *)(head + symshoff +
			 (symshentsize * ELF32_R_SYM(rw(&relp->r_info))));
    if (!symp->st_name) continue;

    name = malloc(sizeof(*name));
    name->next = rel_name_list;
    name->name = strdup(head + strshoff + rw(&symp->st_name));
    name->size = 0;
    name->flags = 0;
    name->filename = strdup(filename);
    name->count = 0;
    name->define = 0;
    rel_name_list = name;
  }

  return (0);
}

static void read_reltxt(char *filename, rh_t rh, rw_t rw, Elf32_Ehdr *ehdr,
			Elf32_Shdr *symtab, Elf32_Shdr *strtab,
			char *section_name)
{
  Elf32_Shdr *reltxt;
  reltxt = get_section(filename, rh, rw, ehdr, section_name);
  if (reltxt) {
    make_reltxt_table(filename, rh, rw, ehdr, reltxt, symtab, strtab);
  }
}

static int readelf(char *filename, char *head)
{
  Elf32_Ehdr *ehdr;
  Elf32_Shdr *symtab;
  Elf32_Shdr *strtab;
  rh_t rh;
  rw_t rw;

  ehdr = (Elf32_Ehdr *)head;
  if (!IS_ELF(*ehdr)) {
    fprintf(stderr, "This is not ELF file. (%s)\n", filename);
    return (1);
  }

  if (ehdr->e_ident[EI_CLASS] != ELF_CLASS) {
    fprintf(stderr, "unknown class. (%d)\n", (int)ehdr->e_ident[EI_CLASS]);
    return (1);
  }

  switch (ehdr->e_ident[EI_DATA]) {
  case ELFDATA2MSB:
    rh = read_half_be;
    rw = read_word_be;
    break;
  case ELFDATA2LSB:
    rh = read_half_le;
    rw = read_word_le;
    break;
  default:
    fprintf(stderr, "unknown endian. (%d)\n", (int)ehdr->e_ident[EI_DATA]);
    return (1);
  }

  if ((rh(&ehdr->e_type) != ET_EXEC) && (rh(&ehdr->e_type) != ET_REL)) {
    fprintf(stderr, "unknown type. (%d)\n", (int)rh(&ehdr->e_type));
    return (1);
  }

  symtab = get_section(filename, rh, rw, ehdr, ".symtab");
  strtab = get_section(filename, rh, rw, ehdr, ".strtab");

  if (symtab && strtab) {
    make_symbol_table(filename, rh, rw, ehdr, symtab, strtab);

    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rel.text");
    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rela.text");
    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rel.data");
    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rela.data");
    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rel.rodata");
    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rela.rodata");
#if 0
    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rel.stab");
    read_reltxt(filename, rh, rw, ehdr, symtab, strtab, ".rela.stab");
#endif
  }

  return (0);
}

static int get_value(const char *s, int len)
{
  char buffer[20];
  memcpy(buffer, s, len);
  buffer[len] = '\0';
  return (atoi(buffer));
}

static char *get_string(const char *s, int maxlen)
{
  char *buffer;
  int len;
  for (len = 0; s[len] != ' ' && s[len] != '/' && s[len] != '\0'; len++) {
    if (maxlen && (len >= maxlen)) break;
  }
  buffer = malloc(len + 1);
  memcpy(buffer, s, len);
  buffer[len] = '\0';
  return (buffer);
}

static int readar(char *filename, char *head, int size)
{
  int offset, soffset;
  char *f, *f2;
  struct ar_hdr *arhdr;
  struct ar_hdr *nhdr;

  nhdr = NULL;
  for (offset = SARMAG; offset < size;) {
    arhdr = (struct ar_hdr *)(head + offset);
    if ((arhdr->ar_name[0] == '/') &&
	(arhdr->ar_name[1] == ' ')) {
      fprintf(stderr, "symbol table found.\n");
    } else if ((arhdr->ar_name[0] == '/') &&
	       (arhdr->ar_name[1] == '/')) {
      fprintf(stderr, "string table found.\n");
      nhdr = arhdr;
    } else {
      f = NULL;
      if (arhdr->ar_name[0] == '/') {
        soffset = get_value(&(arhdr->ar_name[1]), sizeof(arhdr->ar_name) - 1);
        if (nhdr == NULL) {
          fprintf(stderr, "yet not found string table.\n");
        } else {
	  f = get_string((char *)nhdr + sizeof(struct ar_hdr) + soffset, 0);
	}
      } else {
	f = get_string(arhdr->ar_name, sizeof(arhdr->ar_name));
      }
      if (f) {
	fprintf(stderr, "found file %s in %s. ", f, filename);
	if (IS_ELF(*(Elf32_Ehdr *)((char *)arhdr + sizeof(struct ar_hdr)))) {
	  fprintf(stderr, "ELF file reading...\n");
	  f2 = malloc(strlen(f) + strlen(filename) + 4);
	  sprintf(f2, "%s (%s)", f, filename);
	  readelf(f2, (char *)arhdr + sizeof(struct ar_hdr));
	  free(f2);
	} else {
	  fprintf(stderr, "not ELF file.\n");
	}
	free(f);
      }
    }
    offset +=
      sizeof(struct ar_hdr)
      + get_value(arhdr->ar_size, sizeof(arhdr->ar_size));
    offset = ((offset + 1) / 2) * 2;
  }

  return (0);
}

int main(int argc, char *argv[])
{
  int i, fd, size, sizesum;
  char *filename;
  struct stat sb;
  char *head;
  struct name_list *n1;
  struct name_list *n2;
  struct name_list **np;

  for (i = 1; i < argc; i++) {
    filename = argv[i];
    fd = open(filename, O_RDONLY);
    if (fd < 0) continue;
    fstat(fd, &sb);
    size = sb.st_size;
    head = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (!memcmp(head, ARMAG, SARMAG)) {
      fprintf(stderr, "%s is AR file. reading...\n", filename);
      readar(filename, head, size);
    } else if (IS_ELF(*(Elf32_Ehdr *)head)) {
      fprintf(stderr, "%s is ELF file. reading...\n", filename);
      readelf(filename, head);
    } else {
      fprintf(stderr, "Unknown file format. (%s)\n", filename);
      exit (1);
    }

    munmap(head, sb.st_size);
    close(fd);
  }

  fprintf(stderr, "collecting... ");
  for (n1 = sym_name_list; n1; n1 = n1->next) {
    for (np = &(n1->next); *np;) {
      n2 = *np;
      if (!strcmp(n1->name, n2->name)) {
	printf("collect duplicate symbols %s (%s, %s)\n",
	       n1->name, n1->filename, n2->filename);
	free(n1->filename);
	n1->filename = strdup("(duplicate)");
	n1->define += n2->define;
	*np = n2->next;
	free(n2->name);
	free(n2->filename);
	free(n2);
      } else {
	np = &(n2->next);
      }
    }
  }
  fprintf(stderr, "OK.\n");

  fprintf(stderr, "counting... ");
  for (n1 = rel_name_list; n1; n1 = n1->next) {
    for (n2 = sym_name_list; n2; n2 = n2->next) {
      if (!strcmp(n1->name, n2->name)) {
	(n2->count)++;
	break;
      }
    }
  }
  fprintf(stderr, "OK.\n");

  printf("Defined symbol list:\n");
  for (n1 = sym_name_list; n1; n1 = n1->next) {
    printf("%s (Ref:%d, Size:%d)(%s)\n", n1->name, n1->count, n1->size,
	   (n1->flags & NAME_FLAG_NOALLOC) ? "noalloc" : "alloc");
  }

  printf("\nReferenced symbol list:\n");
  for (n1 = rel_name_list; n1; n1 = n1->next) {
    printf("%s\n", n1->name);
  }

  printf("\nDuplicated symbol list:\n");
  sizesum = 0;
  for (n1 = sym_name_list; n1; n1 = n1->next) {
    if (n1->define > 1) {
      printf("%s (Duplicate:%d)\n", n1->name, n1->define);
    }
  }

  printf("\nUnreferenced symbol list:\n");
  sizesum = 0;
  for (n1 = sym_name_list; n1; n1 = n1->next) {
    if (n1->count == 0) {
      printf("%s:\t%s (Size:%d)(%s)\n", n1->filename, n1->name, n1->size,
	     (n1->flags & NAME_FLAG_NOALLOC) ? "noalloc" : "alloc");
      sizesum += n1->size;
    }
  }

  printf("\nUnreferenced symbols size sum: %d byte\n", sizesum);

  exit (0);
}

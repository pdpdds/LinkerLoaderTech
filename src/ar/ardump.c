#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <ar.h>
#include <sys/stat.h>
#include <sys/mman.h>

static int elfdump(char *head)
{
  Elf_Ehdr *ehdr;
  Elf_Shdr *shdr, *shstr, *str, *sym, *rel;
  Elf_Phdr *phdr;
  Elf_Sym *symp;
  Elf_Rel *relp;
  int i, j, size;
  char *sname;

  ehdr = (Elf_Ehdr *)head;

  if (!IS_ELF(*ehdr)) {
    fprintf(stderr, "This is not ELF file.\n");
    return (1);
  }

  if (ehdr->e_ident[EI_CLASS] != ELF_CLASS) {
    fprintf(stderr, "unknown class. (%d)\n", (int)ehdr->e_ident[EI_CLASS]);
    return (1);
  }

  if (ehdr->e_ident[EI_DATA] != ELF_DATA) {
    fprintf(stderr, "unknown endian. (%d)\n", (int)ehdr->e_ident[EI_DATA]);
    return (1);
  }

  /* セクション名格納用セクション(.shstrtab)の取得 */
  shstr = (Elf_Shdr *)(head + ehdr->e_shoff +
		       ehdr->e_shentsize * ehdr->e_shstrndx);

  /* セクション名一覧を表示 */
  printf("Sections:\n");
  for (i = 0; i < ehdr->e_shnum; i++) { /* セクションヘッダテーブルを検索 */
    shdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * i);
    sname = (char *)(head + shstr->sh_offset + shdr->sh_name);
    printf("\t[%d]\t%s\n", i, sname);
    if (!strcmp(sname, ".strtab")) str = shdr;
  }

  /* セグメント一覧を表示 */
  printf("Segments:\n");
  for (i = 0; i < ehdr->e_phnum; i++) { /* プログラムヘッダテーブルを検索 */
    phdr = (Elf_Phdr *)(head + ehdr->e_phoff + ehdr->e_phentsize * i);
    printf("\t[%d]\t", i);
    for (j = 0; j < ehdr->e_shnum; j++) { /* セクションヘッダテーブルを検索 */
      shdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * j);
      size = (shdr->sh_type != SHT_NOBITS) ? shdr->sh_size : 0;
      if (shdr->sh_offset < phdr->p_offset) continue;
      if (shdr->sh_offset + size > phdr->p_offset + phdr->p_filesz) continue;
      sname = (char *)(head + shstr->sh_offset + shdr->sh_name);
      printf("%s ", sname);
    }
    printf("\n");
  }

  /* シンボル名一覧を表示 */
  printf("Symbols:\n");
  for (i = 0; i < ehdr->e_shnum; i++) { /* シンボルテーブルを検索 */
    shdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * i);
    if (shdr->sh_type != SHT_SYMTAB) continue;
    sym = shdr;
    for (j = 0; j < sym->sh_size / sym->sh_entsize; j++) {
      symp = (Elf_Sym *)(head + sym->sh_offset + sym->sh_entsize * j);
      if (!symp->st_name) continue;
      printf("\t[%d]\t%d\t%d\t%s\n",
	     j, (int)ELF_ST_TYPE(symp->st_info), symp->st_size,
	     (char *)(head + str->sh_offset + symp->st_name));
    }
  }

  /* 再配置するシンボル一覧を表示 */
  printf("Relocations:\n");
  for (i = 0; i < ehdr->e_shnum; i++) { /* 再配置テーブルを検索 */
    shdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * i);
    if ((shdr->sh_type != SHT_REL) && (shdr->sh_type != SHT_RELA)) continue;
    rel = shdr;
    for (j = 0; j < rel->sh_size / rel->sh_entsize; j++) {
      relp = (Elf_Rel *)(head + rel->sh_offset + rel->sh_entsize * j);
      symp = (Elf_Sym *)(head + sym->sh_offset +
			 (sym->sh_entsize * ELF_R_SYM(relp->r_info)));
      if (!symp->st_name) continue;
      printf("\t[%d]\t%d\t%s\n",
	     j, ELF_R_SYM(relp->r_info),
	     (char *)(head + str->sh_offset + symp->st_name));
    }
  }

  return (0);
}

int main(int argc, char *argv[])
{
  int fd, size;
  struct stat sb;
  char *head, *fname;
  struct ar_hdr *arhdr, *nhdr = NULL;

  fd = open(argv[1], O_RDONLY);
  if (fd < 0) exit (1);
  fstat(fd, &sb);
  head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);

  if (!memcmp(head, ARMAG, SARMAG)) {
    fprintf(stderr, "This is archive file.\n");
    for (arhdr = (struct ar_hdr *)(head + SARMAG);
	 (char *)arhdr < head + sb.st_size;
	 arhdr = (struct ar_hdr *)((char *)arhdr + sizeof(struct ar_hdr) + size)) {
      size = atoi(arhdr->ar_size);
      if (!memcmp(arhdr->ar_name, "/ ", 2)) {
	fprintf(stderr, "symbol table found.\n");
      } else if (!memcmp(arhdr->ar_name, "//", 2)) {
	fprintf(stderr, "string table found.\n");
	nhdr = arhdr;
      } else {
	if (arhdr->ar_name[0] == '/') {
	  if (nhdr == NULL) {
	    fprintf(stderr, "string table not found.\n");
	    exit (1);
	  }
	  fname = (char *)nhdr + sizeof(struct ar_hdr) + atoi(&arhdr->ar_name[1]);
	} else {
	  fname = arhdr->ar_name;
	}
	fprintf(stderr, "found: %.*s\n", strchr(fname, '/') - fname, fname);
	elfdump((char *)arhdr + sizeof(struct ar_hdr));
      }
      if (size % 2) size++;
    }
  } else {
    elfdump(head);
  }

  munmap(head, sb.st_size);
  close(fd);

  exit (0);
}


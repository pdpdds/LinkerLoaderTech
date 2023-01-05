#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>

static u_int32_t swap_word(u_int32_t value)
{
  u_int32_t ret;
  ret =
    ((value >> 24) & 0x000000ff) |
    ((value >>  8) & 0x0000ff00) |
    ((value <<  8) & 0x00ff0000) |
    ((value << 24) & 0xff000000);
  return (ret);
}

static u_int32_t noswap_word(u_int32_t value)
{
  return (value);
}

static u_int16_t swap_half(u_int16_t value)
{
  u_int16_t ret;
  ret =
    ((value >> 8) & 0x00ff) |
    ((value << 8) & 0xff00);
  return (ret);
}

static u_int16_t noswap_half(u_int16_t value)
{
  return (value);
}

static int readelf(char *head)
{
  Elf_Ehdr *ehdr;
  Elf_Shdr *shdr, *shstr, *str, *sym, *rel;
  Elf_Sym *symp;
  Elf_Rel *relp;
  u_int16_t (*rhalf)(u_int16_t);
  u_int32_t (*rword)(u_int32_t);
  int i, j;

  ehdr = (Elf_Ehdr *)head;
  if ((ehdr->e_ident[EI_MAG0] != ELFMAG0) ||
      (ehdr->e_ident[EI_MAG1] != ELFMAG1) ||
      (ehdr->e_ident[EI_MAG2] != ELFMAG2) ||
      (ehdr->e_ident[EI_MAG3] != ELFMAG3)) {
    fprintf(stderr, "This is not ELF file.\n");
    return (1);
  }

  if (ehdr->e_ident[EI_CLASS] != ELFCLASS32) {
    fprintf(stderr, "unknown class. (%d)\n", (int)ehdr->e_ident[EI_CLASS]);
    return (1);
  }

  switch (ehdr->e_ident[EI_DATA]) {
  case NEED_SWAP:
    rhalf = swap_half;
    rword = swap_word;
    break;
  case UNNEED_SWAP:
    rhalf = noswap_half;
    rword = noswap_word;
    break;
  default:
    fprintf(stderr, "unknown endian. (%d)\n", (int)ehdr->e_ident[EI_DATA]);
    return (1);
  }

  /* セクション名格納用セクション(.shstrtab)の取得 */
  shstr = (Elf_Shdr *)(head + rword(ehdr->e_shoff)
		       + rhalf(ehdr->e_shentsize) * rhalf(ehdr->e_shstrndx));

  /* セクション一覧 */
  printf("Sections:\n");
  for (i = 0; i < rhalf(ehdr->e_shnum); i++) {
    char *sname;
    shdr = (Elf_Shdr *)(head + rword(ehdr->e_shoff) + rhalf(ehdr->e_shentsize) * i);
    sname = (char *)(head + rword(shstr->sh_offset) + rword(shdr->sh_name));
    printf("\t%s\n", sname);
    if (!strcmp(sname, ".strtab")) str = shdr;
  }

  /* シンボルテーブルエントリ一覧 */
  printf("Symbols:\n");
  for (i = 0; i < rhalf(ehdr->e_shnum); i++) {

    shdr = (Elf_Shdr *)(head + rword(ehdr->e_shoff) + rhalf(ehdr->e_shentsize) * i);
    if (rword(shdr->sh_type) != SHT_SYMTAB) continue;

    sym = shdr;

    for (j = 0; j < rword(sym->sh_size); j += rword(sym->sh_entsize)) {
      symp = (Elf_Sym *)(head + rword(sym->sh_offset) + j);
      if (!symp->st_name) continue;
      printf("\t%d\t%d\t%s\n",
	     (int)ELF_ST_TYPE(symp->st_info),
	     rword(symp->st_size),
	     (char *)(head + rword(str->sh_offset) + rword(symp->st_name)));
    }
  }

  /* 再配置エントリ一覧 */
  printf("Relocations:\n");
  for (i = 0; i < rhalf(ehdr->e_shnum); i++) {
    shdr = (Elf_Shdr *)(head + rword(ehdr->e_shoff) + rhalf(ehdr->e_shentsize) * i);
    if ((rword(shdr->sh_type) != SHT_REL) &&
	(rword(shdr->sh_type) != SHT_RELA))
      continue;

    rel = shdr;

    for (j = 0; j < rword(rel->sh_size);
	 j += rword(rel->sh_entsize)) {
      relp = (Elf_Rel *)(head + rword(rel->sh_offset) + j);
      symp = (Elf_Sym *)(head + rword(sym->sh_offset) +
			 (rword(sym->sh_entsize) * ELF_R_SYM(rword(relp->r_info))));
      if (!symp->st_name) continue;
      printf("\t%s\n",
	     (char *)(head + rword(str->sh_offset) + rword(symp->st_name)));
    }
  }

  return (0);
}

int main(int argc, char *argv[])
{
  int fd;
  struct stat sb;
  char *head;

  fd = open(argv[1], O_RDONLY);
  if (fd < 0) exit (1);
  fstat(fd, &sb);
  head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
  readelf(head);
  munmap(head, sb.st_size);
  close(fd);

  exit (0);
}

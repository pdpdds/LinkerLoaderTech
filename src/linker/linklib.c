#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "linklib.h"

/* セクション名を取得 */
static char *get_section_name(Elf_Ehdr *ehdr, Elf_Shdr *shdr)
{
  char *head;
  Elf_Shdr *nhdr;

  head = (char *)ehdr;
  nhdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * ehdr->e_shstrndx);
  return ((char *)(head + nhdr->sh_offset + shdr->sh_name));
}

/* セクション名からセクションヘッダを検索 */
Elf_Shdr *get_section(Elf_Ehdr *ehdr, char *name)
{
  int i;
  char *head;
  Elf_Shdr *shdr;

  head = (char *)ehdr;

  for (i = 0; i < ehdr->e_shnum; i++) {
    shdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * i);
    if (!strcmp(get_section_name(ehdr, shdr), name))
      return (shdr);
  }

  return (NULL);
}

/* すべてのオブジェクトファイルから，シンボルを検索 */
int search_symbol(struct obj objs[], char *name, struct obj *obj)
{
  int i, n;
  char *head;
  Elf_Ehdr *ehdr;
  Elf_Shdr *shdr;
  Elf_Shdr *symtab;
  Elf_Shdr *strtab;
  Elf_Sym *symp;

  for (n = 0; objs[n].filename; n++) {
    ehdr = (Elf_Ehdr *)objs[n].address;
    symtab = get_section(ehdr, ".symtab");
    strtab = get_section(ehdr, ".strtab");
    head = (char *)ehdr;

    if (symtab->sh_entsize != sizeof(Elf_Sym)) {
      fprintf(stderr, "Invalid entry size. (%d)\n", symtab->sh_entsize);
      exit (1);
    }

    for (i = 0; i < symtab->sh_size; i += symtab->sh_entsize) {
      symp = (Elf_Sym *)(head + symtab->sh_offset + i);
      if (!symp->st_name) continue;
      if ((symp->st_shndx == SHN_UNDEF) || (symp->st_shndx == SHN_ABS)) continue;
      if (ELF_ST_BIND(symp->st_info) != STB_GLOBAL) continue;
      if ((ELF_ST_TYPE(symp->st_info) != STT_NOTYPE) &&
	  (ELF_ST_TYPE(symp->st_info) != STT_OBJECT) &&
	  (ELF_ST_TYPE(symp->st_info) != STT_FUNC))
	continue;
      /*
       * アセンブラで定義されたシンボルの場合にはサイズゼロになっているので，
       * 以下のチェックをしてはいけない．(そもそもチェックすべきでない)
       */
      /* if (!symp->st_size) continue; */

      if (!strcmp(name, head + strtab->sh_offset + symp->st_name)) {
	shdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * symp->st_shndx);
	obj->filename = objs[n].filename;
	obj->address  = (char *)(head + shdr->sh_offset + symp->st_value);
	return (0);
      }
    }
  }

  fprintf(stderr, "cannot find symbol %s.\n", name);
  exit (1);
}

/* COMMON シンボルのアドレス割り当てを行う */
int relocate_common_symbol(Elf_Ehdr *ehdr)
{
  int i, n;
  char *head;
  Elf_Shdr *symtab;
  Elf_Shdr *bss;
  Elf_Sym *symp;

  symtab = get_section(ehdr, ".symtab");
  bss = get_section(ehdr, ".bss");
  head = (char *)ehdr;

  if (symtab->sh_entsize != sizeof(Elf_Sym)) {
    fprintf(stderr, "Invalid entry size. (%d)\n", symtab->sh_entsize);
    exit (1);
  }

  n = bss->sh_size;
  for (i = 0; i < symtab->sh_size; i += symtab->sh_entsize) {
    symp = (Elf_Sym *)(head + symtab->sh_offset + i);
    if (symp->st_shndx != SHN_COMMON) continue;
    /*
     * COMMONシンボルでは st_value はアラインメントサイズを
     * 表すようなので，st_value でアラインメントする．
     */
    n = (n + symp->st_value - 1) & ~(symp->st_value - 1);
    symp->st_shndx = bss - (Elf_Shdr *)(head + ehdr->e_shoff);
    symp->st_value = n;
    n += symp->st_size;
  }

  n = (n + 15) & ~15;
  bss->sh_size = n;
  return (0);
}

/* シンボル解決を行う */
static int link_symbol(struct obj objs[], int objnum, Elf_Ehdr *ehdr,
		       Elf_Shdr *reltab, Elf_Shdr *defsec,
		       Elf_Shdr *symtab, Elf_Shdr *strtab)
{
  int i, addr, addend;
  char *head;
  unsigned int *addp;
  Elf_Shdr *shdr;
  Elf_Sym *symp;
  Elf_Rel *relp;
  struct obj obj;

  head = (char *)ehdr;
  for (i = 0; i < reltab->sh_size; i += reltab->sh_entsize) {
    relp = (Elf_Rel *)(head + reltab->sh_offset + i);
    symp = (Elf_Sym *)(head + symtab->sh_offset +
		       (symtab->sh_entsize * ELF_R_SYM(relp->r_info)));
    /*
     * シンボルテーブルがセクションを指す場合には st_name が無いので，
     * 以下のチェックをしてはいけない．
     */
    /* if (!symp->st_name) continue; */

    fprintf(stderr, "%-10s ", objs[objnum].filename);

    if (symp->st_name) {
      fprintf(stderr, "%-12s ", head + strtab->sh_offset + symp->st_name);
    }
    switch (symp->st_shndx) {
    case SHN_UNDEF:
      if (!symp->st_name) {
	fprintf(stderr, "%-12s", "unknown");
      }
      search_symbol(objs, (char *)(head + strtab->sh_offset + symp->st_name), &obj);
      addr = (int)obj.address;
      fprintf(stderr, "%-10s ", obj.filename);
      break;
    case SHN_ABS:
    case SHN_COMMON:
      fprintf(stderr, "invalid Ndx.\n");
      exit (1);
    default:
      shdr = (Elf_Shdr *)(head + ehdr->e_shoff + ehdr->e_shentsize * symp->st_shndx);
      if (!symp->st_name) {
	fprintf(stderr, "%-12s ", get_section_name(ehdr, shdr));
      }
      addr = (int)(head + shdr->sh_offset + symp->st_value);
      fprintf(stderr, "internal   ");
      break;
    }

    addp = (unsigned int *)(head + defsec->sh_offset + relp->r_offset);
    switch (reltab->sh_type) {
    case SHT_REL:
      fprintf(stderr, "REL  ");
      addend = *addp;
      break;
    case SHT_RELA:
      fprintf(stderr, "RELA ");
      addend = ((Elf_Rela *)relp)->r_addend;
      break;
    default:
      fprintf(stderr, "%4d ", reltab->sh_type);
      addend = 0;
      break;
    }

    fprintf(stderr, "%08x %08x %08x ", addend, (int)addp, addr);

    /*
     * 各種の再配置種別に対して，値の補填を行う．ほんとはもっと
     * たくさんの再配置種別の対応が必要だが，とりあえずこれでよい．
     */
    switch (ELF_R_TYPE(relp->r_info)) {
    case R_386_PC32:
      fprintf(stderr, "R_386_PC32\n");
      *addp = addend + (addr - (int)addp);
      break;
    case R_386_32:
      fprintf(stderr, "R_386_32\n");
      *addp = addend + addr;
      break;
    default:
      fprintf(stderr, "unknown(%d)\n", ELF_R_TYPE(relp->r_info));
    }
  }

  return (0);
}

int check_ehdr(Elf_Ehdr *ehdr)
{
  if (!IS_ELF(*ehdr)) {
    fprintf(stderr, "This is not ELF file.\n");
    exit (1);
  }

  if (ehdr->e_ident[EI_CLASS] != ELF_CLASS) {
    fprintf(stderr, "unknown class. (%d)\n", (int)ehdr->e_ident[EI_CLASS]);
    exit (1);
  }

  if (ehdr->e_ident[EI_DATA] != ELF_DATA) {
    fprintf(stderr, "unknown endian. (%d)\n", (int)ehdr->e_ident[EI_DATA]);
    exit (1);
  }

  if (ehdr->e_type != ET_REL) {
    fprintf(stderr, "unknown type. (%d)\n", (int)ehdr->e_type);
    exit (1);
  }

  return (0);
}

int link_objs(struct obj objs[])
{
  int i, j;
  char *name;
  Elf_Ehdr *ehdr;
  Elf_Shdr *reltab;
  Elf_Shdr *defsec;
  Elf_Shdr *symtab;
  Elf_Shdr *strtab;

  fprintf(stderr, "\nfilename   symbol       found      type addend   called   defined  rel type\n");
  fprintf(stderr, "---------- ------------ ---------- ---- -------- -------- -------- ----------\n");

  for (i = 0; objs[i].filename; i++) {
    ehdr = (Elf_Ehdr *)objs[i].address;

    symtab = get_section(ehdr, ".symtab");
    strtab = get_section(ehdr, ".strtab");

    if (symtab && strtab) {
      for (j = 0; j < ehdr->e_shnum; j++) {
	reltab = (Elf_Shdr *)((char *)ehdr + ehdr->e_shoff + ehdr->e_shentsize * j);
	if ((reltab->sh_type == SHT_REL) || (reltab->sh_type == SHT_RELA)) {
	  name = get_section_name(ehdr, reltab);
	  defsec = get_section(ehdr, strchr(name + 1, '.'));
	  link_symbol(objs, i, ehdr, reltab, defsec, symtab, strtab);
	}
      }
    }
  }

  return (0);
}

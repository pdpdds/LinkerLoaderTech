#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "linklib.h"

int main(int argc, char *argv[])
{
  int i, n, c;
  FILE *fp;
  char *outfile, *p;
  struct obj objs[10];
  struct obj obj;
  int (*f)();
  Elf_Ehdr *ehdr;
  Elf_Shdr *shdr;
  Elf_Phdr *phdr;
  static char buffer[64*1024]; /* オブジェクトファイルのロード用バッファ */

  memset(buffer, 0, sizeof(buffer));
  p = buffer;
  outfile = argv[1];

  /* 4KBでアラインメントする */
  p = (char *)(((unsigned int)p + 4095) & ~4095);

  ehdr = (Elf_Ehdr *)p;
  ehdr->e_ident[EI_MAG0]       = ELFMAG0;
  ehdr->e_ident[EI_MAG1]       = ELFMAG1;
  ehdr->e_ident[EI_MAG2]       = ELFMAG2;
  ehdr->e_ident[EI_MAG3]       = ELFMAG3;
  ehdr->e_ident[EI_CLASS]      = ELF_TARG_CLASS;
  ehdr->e_ident[EI_DATA]       = ELF_TARG_DATA;
  ehdr->e_ident[EI_VERSION]    = EV_CURRENT;
  ehdr->e_ident[EI_OSABI]      = ELFOSABI_FREEBSD;
  ehdr->e_ident[EI_ABIVERSION] = 0;

  ehdr->e_type    = ET_EXEC;
  ehdr->e_machine = ELF_TARG_MACH;
  ehdr->e_version = ELF_TARG_VER;

  ehdr->e_entry     = 0; /* 暫定 */
  ehdr->e_phoff     = sizeof(Elf_Ehdr);
  ehdr->e_shoff     = 0;
  ehdr->e_flags     = 0;
  ehdr->e_ehsize    = sizeof(Elf_Ehdr);
  ehdr->e_phentsize = sizeof(Elf_Phdr);
  ehdr->e_phnum     = 1;
  ehdr->e_shentsize = 0;
  ehdr->e_shnum     = 0;
  ehdr->e_shstrndx  = 0;

  phdr = (Elf_Phdr *)((char *)ehdr + ehdr->e_phoff);
  phdr->p_type   = PT_LOAD;
  phdr->p_offset = 0;
  phdr->p_vaddr  = (Elf_Addr)p;
  phdr->p_paddr  = (Elf_Addr)p;
  phdr->p_filesz = 0; /* 暫定 */
  phdr->p_memsz  = 0; /* 暫定 */
  phdr->p_flags  = PF_R | PF_W | PF_X;
  phdr->p_align  = 0x1000;

  p = (char *)p + sizeof(Elf_Ehdr) + sizeof(Elf_Phdr);

  /* 4KBでアラインメントする */
  p = (char *)(((unsigned int)p + 4095) & ~4095);

  fprintf(stderr, "base address is 0x%08x\n", (int)buffer);
  for (n = 0, i = 2; i < argc; n++, i++) {
    objs[n].filename = argv[i];
    fp = fopen(objs[n].filename, "rb");
    if (!fp) {
      fprintf(stderr, "cannot open file %s.\n", objs[n].filename);
      exit (1);
    }
    objs[n].address = p;
    fprintf(stderr, "load to 0x%08x (%s)\n", (int)p, objs[n].filename);
    while ((c = fgetc(fp)) != EOF) {
      *(p++) = c;
    }
    fclose(fp);

    p = (char *)(((unsigned int)p + 15) & ~15);

    check_ehdr((Elf_Ehdr *)objs[n].address);
    relocate_common_symbol((Elf_Ehdr *)objs[n].address);

    /* BSS領域を確保して初期化する */
    shdr = get_section((Elf_Ehdr *)objs[n].address, ".bss");
    if (shdr) {
      /* BSS領域を終端に作成する */
      shdr->sh_offset = p - objs[n].address;
      memset(p, 0, shdr->sh_size);
      p += shdr->sh_size;
    }

    /* 一応16バイトでアラインメントする */
    p = (char *)(((unsigned int)p + 15) & ~15);
  }
  objs[n].filename = NULL;
  objs[n].address  = NULL;

  link_objs(objs);
  search_symbol(objs, "_start", &obj);
  f = (int (*)())obj.address;
  fprintf(stderr, "\n%s is found at 0x%08x (%s).\n\n",
	  "_start", (int)f, obj.filename);
  ehdr->e_entry  = (Elf_Addr)f;
  phdr->p_filesz = (Elf_Size)p - phdr->p_vaddr;
  phdr->p_memsz  = (Elf_Size)p - phdr->p_vaddr;

  fp = fopen(outfile, "wb");
  fwrite((char *)phdr->p_vaddr, phdr->p_filesz, 1, fp);
  fclose(fp);

  exit (0);
}

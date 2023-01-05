#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "linklib.h"

int main(int argc, char *argv[])
{
  int i, n, c, ret;
  FILE *fp;
  char *funcname, *p;
  struct obj objs[10];
  struct obj obj;
  int (*f)();
  Elf_Shdr *shdr;
  static char buffer[64*1024]; /* オブジェクトファイルのロード用バッファ */

  memset(buffer, 0, sizeof(buffer));
  p = buffer;
  funcname = argv[1];

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
  search_symbol(objs, funcname, &obj);
  f = (int (*)())obj.address;
  fprintf(stderr, "\n%s is found at 0x%08x (%s).\n\n",
	  funcname, (int)f, obj.filename);
  ret = f();
  fprintf(stderr, "\n%s return (%d)\n", funcname, ret);

  exit (0);
}

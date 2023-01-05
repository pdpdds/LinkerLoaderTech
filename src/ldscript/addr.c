#include <stdio.h>

extern int *stext,  *etext;
extern int *srdata, *erdata;
extern int *sdata,  *edata;
extern int *sbss,   *ebss;

int dummy = 12345;

int main()
{
  printf("*text = 0x%08x, 0x%08x\n", stext, etext);
  printf("*data = 0x%08x, 0x%08x\n", sdata, edata);
  printf("text  = 0x%08x, 0x%08x\n", (int)&stext,  (int)&etext);
  printf("rdata = 0x%08x, 0x%08x\n", (int)&srdata, (int)&erdata);
  printf("data  = 0x%08x, 0x%08x\n", (int)&sdata,  (int)&edata);
  printf("bss   = 0x%08x, 0x%08x\n", (int)&sbss,   (int)&ebss);
  exit (0);
}

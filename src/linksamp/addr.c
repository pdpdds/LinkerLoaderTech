#include <stdio.h>

extern int value;
extern int stext,  etext;
extern int srdata, erdata;
extern int sdata,  edata;
extern int sbss,   ebss;

int main()
{
  printf("&value  = 0x%08x\n", (int)&value);
  printf("stext   = 0x%08x, etext   = 0x%08x\n", stext, etext);
  printf("sdata   = 0x%08x, edata   = 0x%08x\n", sdata, edata);
  printf("&stext  = 0x%08x, &etext  = 0x%08x\n", (int)&stext,  (int)&etext);
  printf("&srdata = 0x%08x, &erdata = 0x%08x\n", (int)&srdata, (int)&erdata);
  printf("&sdata  = 0x%08x, &edata  = 0x%08x\n", (int)&sdata,  (int)&edata);
  printf("&sbss   = 0x%08x, &ebss   = 0x%08x\n", (int)&sbss,   (int)&ebss);
  exit (0);
}

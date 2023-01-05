#include <stdio.h>

int stext  = 1;
int srdata = 1;
extern int sdata;

int main()
{
  printf("&stext  = 0x%08x, stext  = 0x%08x\n", (int)&stext,  stext);
  printf("&srdata = 0x%08x, srdata = 0x%08x\n", (int)&srdata, srdata);
  printf("&sdata  = 0x%08x, sdata  = 0x%08x\n", (int)&sdata,  sdata);
  exit (0);
}

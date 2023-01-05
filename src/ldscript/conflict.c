#include <stdio.h>

int stext = 1;
extern int srdata;

int main()
{
  printf("text  = %d, 0x%08x\n", stext,  (int)&stext);
  printf("rdata = %d, 0x%08x\n", srdata, (int)&srdata);
  exit (0);
}

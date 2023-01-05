#include <stdio.h>

extern int __fini_array_end;
extern int edata;
extern int end;

int main()
{
  printf("&__fini_array_end = 0x%08x\n", (int)&__fini_array_end);
  printf("&edata            = 0x%08x\n", (int)&edata);
  printf("&end              = 0x%08x\n", (int)&end);
  exit (0);
}

#include <stdio.h>

extern int cvalue;
extern int svalue;
extern int lvalue;
extern int lvalue2;

int main()
{
  printf("&cvalue = 0x%08x, cvalue = 0x%08x\n", (int)&cvalue, cvalue);
  printf("&svalue = 0x%08x, svalue = 0x%08x\n", (int)&svalue, svalue);
  printf("&lvalue = 0x%08x, lvalue = 0x%08x\n", (int)&lvalue, lvalue);
  printf("&lvalue2 = 0x%08x, lvalue2 = 0x%08x\n", (int)&lvalue2, lvalue2);
  exit (0);
}

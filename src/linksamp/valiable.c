#include <stdio.h>

extern char cvalue;
extern short int svalue;
extern long int lvalue;
extern long int lvalue2;

int main()
{
  printf("&cvalue  = 0x%08x, cvalue  = %d\n", (int)&cvalue,  (int)cvalue);
  printf("&svalue  = 0x%08x, svalue  = %d\n", (int)&svalue,  (int)svalue);
  printf("&lvalue  = 0x%08x, lvalue  = %d\n", (int)&lvalue,  (int)lvalue);
  printf("&lvalue2 = 0x%08x, lvalue2 = %d\n", (int)&lvalue2, (int)lvalue2);
  exit (0);
}

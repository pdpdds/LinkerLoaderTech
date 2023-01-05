#include <stdio.h>

extern int extvalue;
extern int extbssvalue;
extern int extfunc(int a);

int main()
{
  int ret;
  printf("main()\n");
  printf("main():extvalue    = %d\n", extvalue);
  printf("main():extbssvalue = %d\n", extbssvalue);
  ret = extfunc(4);
  printf("main():extfunc()   = %d\n", ret);
  exit (0);
}

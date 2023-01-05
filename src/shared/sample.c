#include <stdio.h>

int extvalue = 1;
int extbssvalue;
static int value = 2;
static int bssvalue;

static int func(int a)
{
  printf("func()\n");
  printf("func():extvalue    = %d\n", extvalue);
  printf("func():extbssvalue = %d\n", extbssvalue);
  printf("func():value       = %d\n", value);
  printf("func():bssvalue    = %d\n", bssvalue);
  return (a + extvalue + extbssvalue + value + bssvalue);
}

int extfunc(int a)
{
  int ret;
  printf("extfunc()\n");
  ret = func(a);
  return (ret);
}

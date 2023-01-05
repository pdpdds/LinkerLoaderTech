#include <stdio.h>

void order2();

void order1()
{
  printf("order1()\n");
  order2();
}

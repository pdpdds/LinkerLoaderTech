#include <stdio.h>

static int count;

int main()
{
  for (count = 0;; count++) {
    if (count == 0x1234)
      *(int *)0 = 1;
  }
  exit (0);
}

#include <stdio.h>

char s1[] = "This is array.";
char * s2 = "This is pointer.";

int main()
{
  printf(" s1 = 0x%08x\n", (unsigned int) s1);
  printf("&s1 = 0x%08x\n", (unsigned int)&s1);
  printf(" s2 = 0x%08x\n", (unsigned int) s2);
  printf("&s2 = 0x%08x\n", (unsigned int)&s2);
  printf("sizeof(s1) = %d\n", sizeof(s1));
  printf("sizeof(s2) = %d\n", sizeof(s2));
  exit (0);
}

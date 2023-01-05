#include <stdio.h>

extern char c;
extern int i0, i1, i2;
extern const int ci0, ci1, ci2;
extern char *p0, *p1;
extern char str[];

int main()
{
  printf("   c = %c\n", c);
  printf("  i0 = %d,   i1 = %d,   i2 = %d\n",  i0,  i1,  i2);
  printf(" ci0 = %d,  ci1 = %d,  ci2 = %d\n", ci0, ci1, ci2);
  printf("  p1 = %s,  str = %s\n", p1, str);
  printf("  &c = 0x%08x\n", &c);
  printf(" &i0 = 0x%08x,  &i1 = 0x%08x,  &i2 = 0x%08x\n",  &i0,  &i1,  &i2);
  printf("&ci0 = 0x%08x, &ci1 = 0x%08x, &ci2 = 0x%08x\n", &ci0, &ci1, &ci2);
  printf(" &p1 = 0x%08x, &str = 0x%08x\n", &p1, &str);
  exit (0);
}

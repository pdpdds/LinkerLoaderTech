#include <stdio.h>

static int calc(int i0, int i1, int i2)
{
  return (i0 * i1 * i2);
}

static int func()
{
  int i0;            /* �����å������� */
  static int i1;     /* BSS�ΰ������ */
  static int i2 = 1; /* �ǡ����ΰ������ */
  unsigned int sum = 0;

  for (i0 = 0; i0 < 10; i0++)
    for (i1 = 0; i1 < 10; i1++)
      for (i2 = 0; i2 < 10; i2++)
	sum += calc(i0, i1, i2); /* �ؿ��ƤӽФ������� */

  return (sum);
}

int main(int argc, char *argv[])
{
  int i;
  printf("argc=%d\n", argc);
  for (i = 0; i < argc; i++)
    printf("argv[%d]=%s\n", i, argv[i]);
  printf("sum %d\n", func());
  exit (0);
}

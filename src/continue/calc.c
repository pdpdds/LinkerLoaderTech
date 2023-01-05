#include <stdio.h>
#include <unistd.h>

static int calc(int i0, int i1, int i2)
{
  return (i0 * i1 * i2);
}

int main()
{
  int i0;            /* �����å������� */
  static int i1;     /* BSS�ΰ������ */
  static int i2 = 1; /* �ǡ����ΰ������ */
  unsigned int sum = 0;
  unsigned char c;

  for (i0 = 0; i0 < 20; i0++) {
    for (i1 = 0; i1 < 1000; i1++)
      for (i2 = 0; i2 < 1000; i2++)
	sum += calc(i0, i1, i2); /* �ؿ��ƤӽФ������� */
    c = (i0 % 10) + '0';
    write(1, &c, 1);
  }
  write(1, "\n", 1);

  /* �Ҥä����֤���ɽ�����Ƥ��뤬���ޤ������Ȥ��� */
  while (sum) {
    c = (sum % 10) + '0';
    write(1, &c, 1);
    sum /= 10;
  }
  write(1, "\n", 1);

  exit (0);
}

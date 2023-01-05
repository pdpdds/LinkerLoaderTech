#include <stdio.h>
#include <setjmp.h>

static jmp_buf buf;

int set()
{
  return (_setjmp(buf));
}

int func()
{
  printf("func()\n");
  _longjmp(buf, 1);
  printf("return from _longjmp()\n");
}

int main()
{
  int ret;

  ret = set();
  printf("return from _setjmp()\n");
  if (ret == 0) {
    printf("return with zero.\n");
    func();
    printf("return from func()\n");
  } else {
    /* _longjmp() ��������� */
    printf("ret = %d\n", ret);
  }
  printf("exit.\n");
  exit (0);
}

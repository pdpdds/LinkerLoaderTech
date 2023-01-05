#include <stdio.h>
#include <setjmp.h>

static jmp_buf buf;

int func()
{
  printf("func()\n");
  _longjmp(buf, 1);
  printf("return from _longjmp()\n");
}

int main()
{
  int ret;

  ret = _setjmp(buf);
  printf("return from _setjmp()\n");
  if (ret == 0) {
    printf("return with zero.\n");
    func();
    printf("return from func()\n");
  } else {
    /* _longjmp() ¤«¤é¤ÎÉüµì */
    printf("ret = %d\n", ret);
  }
  printf("exit.\n");
  exit (0);
}

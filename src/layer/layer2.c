#include <stdio.h>

/* extern int num; */ /* num �� localized �ʤΤ� */
void printnum();
void func1();
void func2();

int main()
{
  printnum();
  /* num++;   printnum(); */ /* num �� localized �ʤΤ� */
  func1(); printnum();
  func2(); printnum();
  exit (0);
}

#include <stdio.h>

/* extern int num; */ /* num は localized なので */
void printnum();
void func1();
void func2();

int main()
{
  printnum();
  /* num++;   printnum(); */ /* num は localized なので */
  func1(); printnum();
  func2(); printnum();
  exit (0);
}

#include <stdio.h>

int value;
char buffer[100];

void func1() { value += 1; }
void func2() { value += 2; }
void func3() { value += 4; }

int main()
{
  value = 0; func1(); func2(); func3();
  printf("value = %d\n", value);

  memcpy(func1,  func2, (char *)func3 - (char *)func2);
  memcpy(buffer, func3, (char *)main  - (char *)func3);

  value = 0; func1(); func2();
  ((void(*)())buffer)();
  printf("value = %d\n", value);

  exit (0);
}

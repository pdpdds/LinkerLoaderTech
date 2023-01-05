#include <stdio.h>

void init1() { printf("init1\n"); }
void init2() { printf("init2\n"); }
void init3() { printf("init3\n"); }

void (*fp1)(void) __attribute__((__section__("test_section"))) = init1;
void (*fp2)(void) __attribute__((__section__("test_section"))) = init2;
void (*fp3)(void) __attribute__((__section__("test_section"))) = init3;

extern void (*__start_test_section)(void);
extern void (*__stop_test_section)(void);

int main()
{
  void (**fp)(void);

  printf("__start_test_section = 0x%08x\n", (int)(&__start_test_section));
  printf("__stop_test_section  = 0x%08x\n", (int)(&__stop_test_section));

  for (fp = &__start_test_section; fp < &__stop_test_section; fp++)
    (**fp)();

  exit (0);
}

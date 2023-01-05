#include <stdio.h>

void sample_func_pragma1();
void sample_func_pragma2();
void sample_func_attr1();
void sample_func_attr2();

extern int sample_value_pragma1;
extern int sample_value_pragma2;
extern int sample_value_attr1;
extern int sample_value_attr2;

int main()
{
  sample_func_pragma1();
  sample_func_pragma2();
  sample_func_attr1();
  sample_func_attr2();

  printf("sample_value_pragma1 = %d\n", sample_value_pragma1);
  printf("sample_value_pragma2 = %d\n", sample_value_pragma2);
  printf("sample_value_attr1   = %d\n", sample_value_attr1);
  printf("sample_value_attr2   = %d\n", sample_value_attr2);

  exit (0);
}

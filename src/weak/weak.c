#include <stdio.h>

/* #pragma による weak シンボルの定義(関数) */

#pragma weak sample_func_pragma1 = _sample_func_pragma1
void _sample_func_pragma1()
{
  printf("sample_func_pragma1(weak)\n");
}

#pragma weak sample_func_pragma2
void sample_func_pragma2()
{
  printf("sample_func_pragma2(weak)\n");
}

/* attribute(()) による weak シンボルの定義(関数) */

void sample_func_attr1() __attribute__((weak, alias("_sample_func_attr1")));
void _sample_func_attr1()
{
  printf("sample_func_attr1(weak)\n");
}

void __attribute__((weak)) sample_func_attr2()
{
  printf("sample_func_attr2(weak)\n");
}

/* #pragma による weak シンボルの定義(変数) */

#pragma weak sample_value_pragma1 = _sample_value_pragma1
int _sample_value_pragma1 = -10;

#pragma weak sample_value_pragma2
int sample_value_pragma2 = -20;

/*
 * attribute(()) による weak シンボルの定義(変数)
 * 変数には __attribute__((alias)) は利用できない
 */
int __attribute__((weak)) sample_value_attr1 = -30;
int __attribute__((weak)) sample_value_attr2 = -40;

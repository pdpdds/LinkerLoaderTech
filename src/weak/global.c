#include <stdio.h>

void sample_func_pragma1() { printf("sample_func_pragma1(global)\n"); }
void sample_func_pragma2() { printf("sample_func_pragma2(global)\n"); }
void sample_func_attr1()   { printf("sample_func_attr1(global)\n");   }
void sample_func_attr2()   { printf("sample_func_attr2(global)\n");   }

int sample_value_pragma1 = 10;
int sample_value_pragma2 = 20;
int sample_value_attr1   = 30;
int sample_value_attr2   = 40;

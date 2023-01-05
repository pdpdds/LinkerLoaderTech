#include <stdio.h>
#include <dlfcn.h>

int main()
{
  int ret;
  void *handle;
  int *extvalue_p;
  int *extbssvalue_p;
  int (*extfunc_p)(int a);

  handle = dlopen("./libsample.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "cannot load library.\n");
    exit (1);
  }

  extvalue_p    = dlsym(handle, "extvalue");
  extbssvalue_p = dlsym(handle, "extbssvalue");
  extfunc_p     = dlsym(handle, "extfunc");
  if (!extvalue_p || !extbssvalue_p || !extfunc_p) {
    fprintf(stderr, "fail to find symbol.\n");
    exit (1);
  }

  printf("main()\n");
  printf("main():extvalue    = %d\n", *extvalue_p);
  printf("main():extbssvalue = %d\n", *extbssvalue_p);
  ret = extfunc_p(4);
  printf("main():extfunc()   = %d\n", ret);

  dlclose(handle);
  exit (0);
}

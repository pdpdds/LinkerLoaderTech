int print(int fd, char *s);
int printn(int fd, unsigned int n);

extern int extvalue;
extern int extbssvalue;
int extfunc(int a, int b);

static int value = 10;
static int bssvalue;

static int func()
{
  int ret;
  print(1, "func()\n");

  print(1, "extvalue     = "); printn(1, extvalue);    print(1, "\n");
  print(1, "extbssvalue  = "); printn(1, extbssvalue); print(1, "\n");
  print(1, "value        = "); printn(1, value);       print(1, "\n");
  print(1, "bssvalue     = "); printn(1, bssvalue);    print(1, "\n");
  ret = extfunc(2, 3);
  print(1, "extfunc(2,3) = "); printn(1, ret);         print(1, "\n");

  return (extvalue + extbssvalue + value + bssvalue);
}

int sample_main()
{
  int ret;
  print(1, "sample_main()\n");
  ret = func();
  print(1, "func()       = "); printn(1, ret);      print(1, "\n");
  return (0);
}

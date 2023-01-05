int print(int fd, char *s);
int printn(int fd, unsigned int n);

int extvalue = 20;
int extbssvalue;

int extfunc(int a, int b)
{
  int ret;
  print(1, "extfunc()\n");
  ret = a + b;
  return (ret);
}

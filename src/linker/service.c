#define SYS_write 4 /* sys/syscall.h */

int syscall();

static int _write(int fd, char *s, int n)
{
  return (syscall(SYS_write, fd, s, n));
}

static int slen(char *s)
{
  int n = 0;
  while (s[n]) n++;
  return (n);
}

int print(int fd, char *s)
{
  return (_write(fd, s, slen(s)));
}

int printn(int fd, unsigned int n)
{
  char s[20];
  char *p = &s[sizeof(s)];
  *(--p) = '\0';
  do {
    *(--p) = '0' + (n % 10);
    n /= 10;
  } while (n);
  return (print(fd, p));
}

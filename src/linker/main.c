int sample_main();
int print(int fd, char *s);
int printn(int fd, unsigned int n);

int main(int argc, char *argv[])
{
  int i;
  print(1, "argc = ");
  printn(1, argc);
  for (i = 0; i < argc; i++) {
    print(1, " ");
    print(1, argv[i]);
  }
  print(1, "\n");

  sample_main();
  return (0);
}

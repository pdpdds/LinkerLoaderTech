#include <stdio.h>
#include <string.h>

int app1_main(int argc, char *argv[]);
int app2_main(int argc, char *argv[]);
void combine_exit(int status);

int main(int argc, char *argv[])
{
  char *ptr;

  printf("combine_main()\n");

  ptr = rindex(argv[0], '/');
  if (ptr) ptr++;
  else ptr = argv[0];

  if (!strcmp(ptr, "app1")) return (app1_main(argc, argv));
  if (!strcmp(ptr, "app2")) return (app2_main(argc, argv));

  printf("Unknown command.\n");
  exit (-1);
}

void combine_exit(int status)
{
  printf("combine_exit(%d)\n", status);
  exit (status);
}

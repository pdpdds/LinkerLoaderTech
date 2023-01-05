#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ar.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
  int fd, size;
  struct stat sb;
  char *head, *fname;
  struct ar_hdr *arhdr, *nhdr = NULL;

  fd = open(argv[1], O_RDONLY);
  if (fd < 0) exit (1);
  fstat(fd, &sb);
  head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);

  if (memcmp(head, ARMAG, SARMAG)) {
    fprintf(stderr, "This is not archive file. (%s)\n", argv[1]);
    exit (1);
  }

  for (arhdr = (struct ar_hdr *)(head + SARMAG);
       (char *)arhdr < head + sb.st_size;
       arhdr = (struct ar_hdr *)((char *)arhdr + sizeof(struct ar_hdr) + size)) {
    size = atoi(arhdr->ar_size);
    if (!memcmp(arhdr->ar_name, "/ ", 2)) {
      fprintf(stderr, "symbol table found.\n");
    } else if (!memcmp(arhdr->ar_name, "//", 2)) {
      fprintf(stderr, "string table found.\n");
      nhdr = arhdr;
    } else {
      if (arhdr->ar_name[0] == '/') {
        if (nhdr == NULL) {
          fprintf(stderr, "string table not found.\n");
	  exit (1);
        }
	fname = (char *)nhdr + sizeof(struct ar_hdr) + atoi(&arhdr->ar_name[1]);
      } else {
	fname = arhdr->ar_name;
      }
      printf("%.*s\t%d\n", strchr(fname, '/') - fname, fname, size);
    }
    if (size % 2) size++;
  }

  munmap(head, sb.st_size);
  close(fd);

  exit (0);
}

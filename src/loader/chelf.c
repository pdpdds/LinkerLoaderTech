#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ar.h>
#include <elf.h>
#include <setjmp.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/param.h>
#include <sys/procfs.h>

static Elf_Phdr *get_phdr(Elf_Ehdr *ehdr, int num)
{
  Elf_Phdr *phdr;
  if ((num < 0) || (num >= ehdr->e_phnum)) {
    fprintf(stderr, "cannot find phdr (%d)\n", num);
    return (NULL);
  }
  phdr = (Elf_Phdr *)((char *)ehdr + ehdr->e_phoff + ehdr->e_phentsize * num);
  return (phdr);
}

static Elf_Shdr *get_shdr(Elf_Ehdr *ehdr, int num)
{
  Elf_Shdr *shdr;
  if ((num < 0) || (num >= ehdr->e_shnum)) {
    fprintf(stderr, "cannot find shdr (%d)\n", num);
    return (NULL);
  }
  shdr = (Elf_Shdr *)((char *)ehdr + ehdr->e_shoff + ehdr->e_shentsize * num);
  return (shdr);
}

static Elf_Shdr *search_shdr(Elf_Ehdr *ehdr, char *name)
{
  int i;
  Elf_Shdr *shdr;
  Elf_Shdr *nhdr;

  nhdr = get_shdr(ehdr, ehdr->e_shstrndx);
  if (!nhdr) return (NULL);

  for (i = 0; i < ehdr->e_shnum; i++) {
    shdr = get_shdr(ehdr, i);
    if (!shdr) continue;
    if (!strcmp((char *)ehdr + nhdr->sh_offset + shdr->sh_name, name)) {
      fprintf(stderr, "found %s\n", name);
      return (shdr);
    }
  }

  fprintf(stderr, "cannot find shdr %s\n", name);
  return (NULL);
}

static int chelf(char *head, int argc, char *argv[])
{
  int i;
  Elf_Ehdr *ehdr;
  Elf_Phdr *phdr;
  Elf_Shdr *shdr;

  ehdr = (Elf_Ehdr *)head;
  if (!IS_ELF(*ehdr)) {
    fprintf(stderr, "This is not ELF file.\n");
    return (-1);
  }

  if (ehdr->e_ident[EI_CLASS] != ELF_CLASS) {
    fprintf(stderr, "unknown class. (%d)\n", (int)ehdr->e_ident[EI_CLASS]);
    return (-1);
  }

  if (ehdr->e_ident[EI_DATA] != ELF_DATA) {
    fprintf(stderr, "unknown endian. (%d)\n", (int)ehdr->e_ident[EI_DATA]);
    return (-1);
  }

  for (i = 0; i < argc; i++) {
    switch (argv[i++][0]) {
    case 'P':
      phdr = get_phdr(ehdr, atoi(argv[i++]));
      phdr->p_type = strtol(argv[i++], NULL, 0);
      break;
    case 'p':
      phdr = get_phdr(ehdr, atoi(argv[i++]));
      phdr->p_flags = strtol(argv[i++], NULL, 0);
      break;
    case 'S':
      shdr = search_shdr(ehdr, argv[i++]);
      shdr->sh_type = strtol(argv[i++], NULL, 0);
      break;
    case 's':
      shdr = search_shdr(ehdr, argv[i++]);
      shdr->sh_flags = strtol(argv[i++], NULL, 0);
      break;
    }
  }

  return (0);
}

int main(int argc, char *argv[])
{
  int fd, size;
  char *filename;
  struct stat sb;
  char *head;

  if (argc < 2) {
    fprintf(stderr, "specify filename.\n");
    exit (1);
  }

  filename = argv[1];
  fd = open(filename, O_RDWR);
  if (fd < 0) {
    fprintf(stderr, "cannot open file. (%s)\n", filename);
    exit (1);
  }
  fstat(fd, &sb);
  size = sb.st_size;
  head = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

  if (chelf(head, argc - 2, argv + 2) < 0) {
    fprintf(stderr, "fail to change flags.\n");
  }

  close(fd);

  exit (0);
}

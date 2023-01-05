#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef void (*func_t)();

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

/* ���������򥻥������̾�Ǹ��� */
static Elf_Shdr *search_shdr(Elf_Ehdr *ehdr, char *name)
{
  int i;
  Elf_Shdr *shdr;
  Elf_Shdr *nhdr;

  nhdr = get_shdr(ehdr, ehdr->e_shstrndx);

  for (i = 0; i < ehdr->e_shnum; i++) {
    shdr = get_shdr(ehdr, i);
    if (!strcmp((char *)ehdr + nhdr->sh_offset + shdr->sh_name, name)) {
      fprintf(stderr, "found %s\n", name);
      return (shdr);
    }
  }

  fprintf(stderr, "cannot find shdr %s\n", name);
  return (NULL);
}

static func_t load_file(char *head)
{
  int i;
  Elf_Ehdr *ehdr;
  Elf_Phdr *phdr;
  Elf_Shdr *shdr;
  func_t f;

  ehdr = (Elf_Ehdr *)head;
  if (!IS_ELF(*ehdr)) {
    fprintf(stderr, "This is not ELF file.\n");
    return (NULL);
  }

  if (ehdr->e_ident[EI_CLASS] != ELF_CLASS) {
    fprintf(stderr, "unknown class. (%d)\n", (int)ehdr->e_ident[EI_CLASS]);
    return (NULL);
  }

  if (ehdr->e_ident[EI_DATA] != ELF_DATA) {
    fprintf(stderr, "unknown endian. (%d)\n", (int)ehdr->e_ident[EI_DATA]);
    return (NULL);
  }

  if (ehdr->e_type != ET_EXEC) {
    fprintf(stderr, "unknown type. (%d)\n", (int)ehdr->e_type);
    return (NULL);
  }

  for (i = 0; i < ehdr->e_phnum; i++) {
    fprintf(stderr, "Program Header %d:", i);
    phdr = (Elf_Phdr *)(head + ehdr->e_phoff + ehdr->e_phentsize * i);
    switch (phdr->p_type) {
    case PT_LOAD:
      fprintf(stderr, " Type:LOAD");
      /*
       * ����˥��ɤ��롥
       * ��󥫥�����ץȤ�����ǥƥ������ΰ����Ƭ�˶������äƤ��뤿�ᡤ
       * ��ʬ���Ȥ�񤭴����Ƥ��ޤ����ȤϤʤ���
       */
      memcpy((char *)phdr->p_vaddr, head + phdr->p_offset, phdr->p_filesz);
      fprintf(stderr, " (loaded)\n");
      break;
    default:
      fprintf(stderr, " Type:OTHER\n");
    }
  }

  /* BSS�ΰ�򥯥ꥢ */
  shdr = search_shdr(ehdr, ".bss");
  if (shdr) {
    fprintf(stderr, "clear BSS: 0x%08x, 0x%08x\n",
	    shdr->sh_addr, shdr->sh_size);
    memset((char *)shdr->sh_addr, 0, shdr->sh_size);
  }

  f = (func_t)ehdr->e_entry;
  fprintf(stderr, "Entry Point: 0x%08x\n", (int)f);

  return (f);
}

#define USE_LOADER_ARGV

int main(int argc, char *argv[])
{
  int fd;
  struct stat sb;
  char *head;
  func_t f;
  static char filename[128]; /* ���ɤ����ץ������Ϥ������γ�Ǽ�� */
#ifdef USE_LOADER_ARGV
  static char **stackp;
#endif

  strcpy(filename, argv[1]);
  fprintf(stderr, "open file. (%s)\n", filename);
  fd = open(filename, O_RDONLY);
  if (fd < 0) {
    fprintf(stderr, "cannot open file. (%s)\n", filename);
    exit (1);
  }
  fstat(fd, &sb);
  head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
  f = load_file(head);
  if (f == NULL) {
    fprintf(stderr, "fail to load file.\n");
    exit (1);
  }

  close(fd);

  fprintf(stderr, "jump to entry point.\n");

  /*
   * ����ȥ�ݥ���Ȥ˥����פ������ˡ�������������롥
   * ���������֤˴ؤ��Ƥ� /usr/src/lib/csu/i386-elf/crt1.c �򻲾ȡ�
   */
#ifndef USE_LOADER_ARGV
  asm volatile ("pushl $0");                  /* env[0]  = NULL */
  asm volatile ("pushl $0");                  /* argv[1] = NULL */
  asm volatile ("pushl %0" :: "m"(filename)); /* argv[0] = filename */
  asm volatile ("pushl $1");                  /* argc    = 1 */
#else
  argv[0] = (char *)(argc - 1);
  stackp = &argv[0];
  asm volatile ("movl %0,%%esp" :: "m"(stackp));
#endif

  /*
   * ����ȥ�ݥ���Ȥ˥����ס�
   * (*f)(argc, argv[0], argv[1], env[0]); �Τ褦�ˤ��ƴؿ��ƤӽФ���
   * �����פ������Ȥ���������ؿ��ƤӽФ��ˤ���� call ̿��ˤʤäƤ��ޤ���
   * �����å���������Ϥ���Ǽ����ƥ����å�������Ƥ��ޤ��Τǡ�
   * jmp �ǥ����פ��롥
   */
  asm volatile ("jmp *%0" :: "m"(f));

  /* �����ˤ���ʤ� */
  exit (0);
}

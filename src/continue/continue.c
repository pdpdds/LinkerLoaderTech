#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <setjmp.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/param.h>
#include <sys/procfs.h>

static prstatus_t status;     /* sys/procfs.h: prstatus_t */
static prfpregset_t fpregset; /* machine/reg.h: struct fpreg */
static prpsinfo_t psinfo;     /* sys/procfs.h: prpsinfo_t */

static int load_note(char *head, Elf_Phdr *phdr)
{
  Elf_Note *nhdr;
  char *nname;
  char *ndesc;
  char *nnext;

  for (nhdr = (Elf_Note *)(head + phdr->p_offset);
       nhdr < (Elf_Note *)(head + phdr->p_offset + phdr->p_filesz);
       nhdr = (Elf_Note *)nnext) {
    nname = (char *)nhdr + sizeof(*nhdr);
    /* �ʲ��� Elf_Size ��(�狼��ˤ�������)sys/elf_generic.h ��������Ƥ��� */
    ndesc = nname + roundup2(nhdr->n_namesz, sizeof(Elf_Size));
    nnext = ndesc + roundup2(nhdr->n_descsz, sizeof(Elf_Size));

    fprintf(stderr, "  Note:%s", nname);

    switch (nhdr->n_type) {
    case NT_PRSTATUS: /* Process status */
      fprintf(stderr, "(PRSTATUS)\n");
      memcpy(&status, ndesc, sizeof(status));
      break;
    case NT_FPREGSET: /* Floating point registers */
      fprintf(stderr, "(PRREGSET)\n");
      memcpy(&fpregset, ndesc, sizeof(fpregset));
      break;
    case NT_PRPSINFO: /* Process state info */
      fprintf(stderr, "(PRPSINFO)\n");
      memcpy(&psinfo, ndesc, sizeof(psinfo));
      break;
    default:
      fprintf(stderr, "(UNKNOWN)\n");
    }
  }
  return (0);
}

static int load_file(char *head)
{
  int i;
  Elf_Ehdr *ehdr;
  Elf_Phdr *phdr;

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

  if ((ehdr->e_type != ET_EXEC) && (ehdr->e_type != ET_CORE)) {
    fprintf(stderr, "unknown type. (%d)\n", (int)ehdr->e_type);
    return (-1);
  }

  for (i = 0; i < ehdr->e_phnum; i++) {
    fprintf(stderr, "Program Header %d:", i);
    phdr = (Elf_Phdr *)(head + ehdr->e_phoff + ehdr->e_phentsize * i);
    switch (phdr->p_type) {
    case PT_NOTE:
      fprintf(stderr, " Type:NOTE\n");
      load_note(head, phdr);
      break;
    case PT_LOAD:
      fprintf(stderr, " Type:LOAD");
      /*
       * ����˥��ɤ��롥
       * ��󥫥�����ץȤ�����ǥƥ������ΰ����Ƭ�˶������äƤ��뤿�ᡤ
       * ��ʬ���Ȥ�񤭴����Ƥ��ޤ����ȤϤʤ���
       * �����å��ΰ����ɤ���뤬����ʬ���ȤΥ����å��� main() ����Ƭ��
       * ���Ѥξ������Ѥ���褦�����ꤷ�Ƥ���Τǡ���ʬ���ȤΥ����å���
       * ��񤭤��Ƥ��ޤ����ȤϤʤ���
       */
      memcpy((char *)phdr->p_vaddr, head + phdr->p_offset, phdr->p_filesz);
      fprintf(stderr, " (loaded)\n");
      break;
    default:
      fprintf(stderr, " Type:OTHER\n");
    }
  }

  return (0);
}

/* #define USE_LONGJMP */

int jump()
{
#ifdef USE_LONGJMP
  jmp_buf buf;
#endif

  /* �ѿ����쥸�����˳�����Ƥ���Ȥޤ����Τ� static �ˤ��� */
  static gregset_t *gregsetp;

  gregsetp = &status.pr_reg; /* machine/reg.h: struct reg */
  fprintf(stderr, "register setting.\n");
  fprintf(stderr, "fs     %08x  ", gregsetp->r_fs);
  fprintf(stderr, "es     %08x  ", gregsetp->r_es);
  fprintf(stderr, "ds     %08x  ", gregsetp->r_ds);
  fprintf(stderr, "edi    %08x\n", gregsetp->r_edi);
  fprintf(stderr, "esi    %08x  ", gregsetp->r_esi);
  fprintf(stderr, "ebp    %08x  ", gregsetp->r_ebp);
  fprintf(stderr, "isp    %08x  ", gregsetp->r_isp);
  fprintf(stderr, "ebx    %08x\n", gregsetp->r_ebx);
  fprintf(stderr, "edx    %08x  ", gregsetp->r_edx);
  fprintf(stderr, "ecx    %08x  ", gregsetp->r_ecx);
  fprintf(stderr, "eax    %08x  ", gregsetp->r_eax);
  fprintf(stderr, "trapno %08x\n", gregsetp->r_trapno);
  fprintf(stderr, "err    %08x  ", gregsetp->r_err);
  fprintf(stderr, "eip    %08x  ", gregsetp->r_eip);
  fprintf(stderr, "cs     %08x  ", gregsetp->r_cs);
  fprintf(stderr, "eflags %08x\n", gregsetp->r_eflags);
  fprintf(stderr, "esp    %08x  ", gregsetp->r_esp);
  fprintf(stderr, "ss     %08x  ", gregsetp->r_ss);
  fprintf(stderr, "gs     %08x\n", gregsetp->r_gs);

  fprintf(stderr, "set registers and stack, and jump to abort point.\n");

#ifdef USE_LONGJMP
  /*
   * �ʲ�������ˤĤ��Ƥ� setjmp()/longjmp()
   * (/usr/src/lib/libc/i386/gen)�򻲾ȡ�
   */
  buf[0]._jb[0] = gregsetp->r_eip;
  buf[0]._jb[1] = gregsetp->r_ebx;
  buf[0]._jb[2] = gregsetp->r_esp;
  buf[0]._jb[3] = gregsetp->r_ebp;
  buf[0]._jb[4] = gregsetp->r_esi;
  buf[0]._jb[5] = gregsetp->r_edi;
  /* buf[0]._jb[6] = ??? */

  longjmp(buf, gregsetp->r_eax);
#else
  asm volatile ("movl %0,%%edx" :: "m"(gregsetp));

  /* �Ƽ�쥸���������� */
  asm volatile ("movl  0(%edx),%fs");
  asm volatile ("movl  4(%edx),%es");
  asm volatile ("movl  8(%edx),%ds");
  asm volatile ("movl 12(%edx),%edi");
  asm volatile ("movl 16(%edx),%esi");
  asm volatile ("movl 20(%edx),%ebp");
/*asm volatile ("movl 24(%edx),%isp");    */ /* ������֥��Բ� */
  asm volatile ("movl 28(%edx),%ebx");
/*asm volatile ("movl 32(%edx),%edx");    */ /* �Ǹ�˹Ԥ� */
  asm volatile ("movl 36(%edx),%ecx");
/*asm volatile ("movl 40(%edx),%eax");    */ /* �Ǹ�˹Ԥ� */
/*asm volatile ("movl 44(%edx),%trapno"); */ /* ������֥��Բ� */
/*asm volatile ("movl 48(%edx),%err");    */ /* ������֥��Բ� */
/*asm volatile ("movl 52(%edx),%eip");    */ /* �Ǹ�˹Ԥ� */
/*asm volatile ("movl 56(%edx),%cs");     */ /* ������̿�� */
/*asm volatile ("movl 60(%edx),%eflags"); */ /* ������֥��Բ� */
/*asm volatile ("movl 64(%edx),%esp");    */ /* �Ǹ�˹Ԥ� */
  asm volatile ("movl 68(%edx),%ss");
  asm volatile ("movl 72(%edx),%gs");

  asm volatile ("movl 64(%edx),%esp"); /* �����å��ݥ������� */
  asm volatile ("pushl 52(%edx)");     /* �¹ԺƳ����ɥ쥹�򥹥��å������� */
  asm volatile ("movl 40(%edx),%eax");
  asm volatile ("movl 32(%edx),%edx");

  /* ret ��¹Ԥ���ȡ������å�����������Ϥ��ɤ߹��ߡ������˥����פ��� */
  asm volatile ("ret");
#endif

  /* �����ˤ���ʤ� */
  return (0);
}

int main(int argc, char *argv[])
{
  int i, fd;
  struct stat sb;
  char *filename;
  char *head;
  static char stack[0x1000];
  static char *stackp;

  /*
   * ��������פΥ��ɻ��ˤϥ����å�����ɤ���롥���Τޤޥ��ɤ���ȡ�
   * ��ʬ���Ȥ�������Υ����å����񤭤��Ƥ��ޤ����Ȥˤʤ롥
   * ��äƥ����å��Ѥ��ΰ���̤˳��ݤ�������������Ѥ��롥
   * (������Ĺ�ʤΤǡ������Τۤ��������Ѥ���)
   * main() �Υ������ѿ��Ϥ��Ǥ˥����å���ˤ��뤿�ᡤ����äƤ��Τ֤��
   * �������ʤ���Фʤ�ʤ��Τǡ�;͵�򸫤�256�Х��ȤΥѥǥ��󥰤򤹤롥
   * �����ǥ����å��ݥ��󥿤��Ѳ�����Τǡ����������˥������ѿ���
   * �ͤ����ꤷ�Ƥ���ȡ��ͤ������Τ���ա�
   */
  stackp = stack + sizeof(stack) - 256;
  asm volatile ("movl %0,%%esp" :: "m"(stackp)); /* �����å��ݥ��󥿤����� */

  for (i = 1; i < argc; i++) {
    filename = argv[i];
    fprintf(stderr, "open file. (%s)\n", filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
      fprintf(stderr, "cannot open file.\n");
      exit (1);
    }
    fstat(fd, &sb);
    head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (load_file(head) < 0) {
      fprintf(stderr, "fail to read core.\n");
    }
    close(fd);
  }

  jump();

  exit (0);
}

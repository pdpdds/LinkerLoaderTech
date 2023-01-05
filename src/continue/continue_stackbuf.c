#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <setjmp.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/param.h>
#include <sys/procfs.h>

static char stackbuf[0x40000];
static char *stack = NULL;
static int stacksize = 0;

static prstatus_t status; /* sys/procfs.h: prstatus_t */
static prfpregset_t fpregset; /* machine/reg.h: struct fpreg */
static prpsinfo_t psinfo; /* sys/procfs.h: prpsinfo_t */

static int load_note(char *head, Elf_Phdr *phdr)
{
  Elf_Note *nhdr;
  char *nname;
  char *ndesc;

  for (nhdr = (Elf_Note *)(head + phdr->p_offset);
       nhdr < (Elf_Note *)(head + phdr->p_offset + phdr->p_filesz);
       ) {
    nname = (char *)nhdr + sizeof(*nhdr);
    ndesc = nname + roundup2(nhdr->n_namesz, sizeof(Elf_Size));
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

    /* Elf_Size ��(�狼��ˤ�������)sys/elf_generic.h ��������Ƥ��� */
    nhdr = (Elf_Note *)(ndesc + roundup2(nhdr->n_descsz, sizeof(Elf_Size)));
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

  if ((ehdr->e_type != ET_EXEC) &&
      (ehdr->e_type != ET_CORE)) {
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
      fprintf(stderr, " Type: LOAD\n");
      if (phdr->p_vaddr > 0xbf000000) {
	/* �����å������ѤΥХåե�����¸���Ƥ��������Ȥ����줹�� */
	memcpy(stackbuf, head + phdr->p_offset, phdr->p_filesz);
	stack = (char *)phdr->p_vaddr;
	stacksize = phdr->p_memsz;
      } else {
	memcpy((char *)phdr->p_vaddr, head + phdr->p_offset, phdr->p_filesz);
      }
      break;
    default:
      fprintf(stderr, " Type: OTHER\n");
    }
  }

  return (0);
}

/* #define USE_STATIC_STACK */
#define USE_LONGJMP

int jump()
{
  /*
   * �ѿ���ɬ�� static �ˤ��뤳�ȡ�
   * �������å���񤭴�����Τǡ����ܤȤ��ƥ������ѿ������ѤǤ��ʤ��Τ�
   * ���쥸������񤭴�����Τǡ��ѿ����쥸�����˳�����Ƥ���Ȥޤ����Τ�
   */
  static gregset_t *gregsetp;
  static char *stackp;

#ifdef USE_LONGJMP
  static jmp_buf buf;
#endif

  fprintf(stderr, "register setting.\n");

  if (!stack) return (-1);

  gregsetp = &status.pr_reg; /* machine/reg.h: struct reg */
  stackp = stackbuf + (status.pr_reg.r_esp - (unsigned int)stack);

  fprintf(stderr, "fs     %08x\n", status.pr_reg.r_fs);
  fprintf(stderr, "es     %08x\n", status.pr_reg.r_es);
  fprintf(stderr, "ds     %08x\n", status.pr_reg.r_ds);
  fprintf(stderr, "edi    %08x\n", status.pr_reg.r_edi);
  fprintf(stderr, "esi    %08x\n", status.pr_reg.r_esi);
  fprintf(stderr, "ebp    %08x\n", status.pr_reg.r_ebp);
  fprintf(stderr, "isp    %08x\n", status.pr_reg.r_isp);
  fprintf(stderr, "ebx    %08x\n", status.pr_reg.r_ebx);
  fprintf(stderr, "edx    %08x\n", status.pr_reg.r_edx);
  fprintf(stderr, "ecx    %08x\n", status.pr_reg.r_ecx);
  fprintf(stderr, "eax    %08x\n", status.pr_reg.r_eax);
  fprintf(stderr, "trapno %08x\n", status.pr_reg.r_trapno);
  fprintf(stderr, "err    %08x\n", status.pr_reg.r_err);
  fprintf(stderr, "eip    %08x\n", status.pr_reg.r_eip);
  fprintf(stderr, "cs     %08x\n", status.pr_reg.r_cs);
  fprintf(stderr, "eflags %08x\n", status.pr_reg.r_eflags);
  fprintf(stderr, "esp    %08x\n", status.pr_reg.r_esp);
  fprintf(stderr, "ss     %08x\n", status.pr_reg.r_ss);
  fprintf(stderr, "gs     %08x\n", status.pr_reg.r_gs);

  fprintf(stderr, "set stack and register, and jump to entry point.\n");

  {
    static char s[0x1000];
    static char *sp;
    sp = s + sizeof(s) - 16; /* ������Ĺ�ʤΤǡ�16�ϰ����Τ���Υѥǥ��� */
    asm volatile ("movl %0,%%esp" :: "rm"(sp));
  }

#ifndef USE_STATIC_STACK
  /*
   * �����å��ΰ������
   * ��ʬ���ȤΥ����å��ΰ���񤭤��뤿�ᡤ�����å������ѤǤ��ʤ���
   * ��äƴؿ��ƤӽФ���������ѿ������ѤϤǤ��ʤ��Τǡ�
   * memcpy() ��Ȥ鷺�˼����ǥ��ԡ����롥
   * �ޤ����ʹߤǤϴؿ��ƤӽФ���ԤäƤϤ����ʤ���
   * (�����å����˲����Ƥ��ޤ��Τ�)
   * ����ѥ��餬�����å������Ѥ���褦�ʥ����ɤ��Ǥ����ˤ���ա�
   * ���μ�Υ����ɤ�񤯤Ȥ�����դȤ��ơ������å��ݥ��󥿤��ɤ���ؤ��Ƥ��ơ�
   * �������ѿ���ؿ��ƽФ��ϥ����å������Ѥ��뤳�Ȥ��˰ռ����뤳�ȡ�
   */
#if 0
  for (i = 0; i < stacksize; i++) {
    stack[i] = stackbuf[i];
  }
#else
  memcpy(stack, stackbuf, stacksize);
#endif
#endif

#ifdef USE_LONGJMP
  /*
   * �쥸����������ˤĤ��Ƥϡ�setjmp()/longjmp()
   * (/usr/src/lib/libc/i386/gen)�򻲾ȡ�
   */
  buf[0]._jb[0] = status.pr_reg.r_eip;
  buf[0]._jb[1] = status.pr_reg.r_ebx;
#ifndef USE_STATIC_STACK
  buf[0]._jb[2] = status.pr_reg.r_esp;
#else
  buf[0]._jb[2] = stackp;
#endif
  buf[0]._jb[3] = status.pr_reg.r_ebp;
  buf[0]._jb[4] = status.pr_reg.r_esi;
  buf[0]._jb[5] = status.pr_reg.r_edi;
  /* buf[0]._jb[6] = ??? */

  longjmp(buf, status.pr_reg.r_eax);
#else
  asm volatile ("movl %0,%%edx" :: "rm"(gregsetp));

  asm volatile ("movl  0(%edx),%fs");
  asm volatile ("movl  4(%edx),%es");
  asm volatile ("movl  8(%edx),%ds");
  asm volatile ("movl 12(%edx),%edi");
  asm volatile ("movl 16(%edx),%esi");
  asm volatile ("movl 20(%edx),%ebp");
  /* asm volatile ("movl 24(%edx),%isp");    */ /* ������֥��Բ� */
  asm volatile ("movl 28(%edx),%ebx");
  /* asm volatile ("movl 32(%edx),%edx");    */ /* �Ǹ�˹Ԥ� */
  asm volatile ("movl 36(%edx),%ecx");
  /* asm volatile ("movl 40(%edx),%eax");    */ /* �Ǹ�˹Ԥ� */
  /* asm volatile ("movl 44(%edx),%trapno"); */ /* ������֥��Բ� */
  /* asm volatile ("movl 48(%edx),%err");    */ /* ������֥��Բ� */
  /* asm volatile ("movl 52(%edx),%eip");    */ /* �Ǹ�˹Ԥ� */
  /* asm volatile ("movl 56(%edx),%cs");     */ /* ������̿�� */
  /* asm volatile ("movl 60(%edx),%eflags"); */ /* ������֥��Բ� */
  /* asm volatile ("movl 64(%edx),%esp");    */ /* �Ǹ�˹Ԥ� */
  asm volatile ("movl 68(%edx),%ss");
  asm volatile ("movl 72(%edx),%gs");

  /* �����å��ݥ������� */
#ifndef USE_STATIC_STACK
  asm volatile ("movl 64(%edx),%esp");
#else
  asm volatile ("movl %0,%%esp" :: "rm"(stackp));
#endif

  /* �¹ԺƳ����ɥ쥹���� */
  asm volatile ("pushl 52(%edx)");

  asm volatile ("movl 40(%edx),%eax");
  asm volatile ("movl 32(%edx),%edx");
  asm volatile ("ret");
#endif

  /* �����ˤ���ʤ� */
  return (0);
}

int main(int argc, char *argv[])
{
  int i, fd, size;
  char *filename;
  struct stat sb;
  char *head;

  for (i = 1; i < argc; i++) {
    filename = argv[i];
    fprintf(stderr, "open file. (%s)\n", filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
      fprintf(stderr, "cannot open file. (%s)\n", filename);
      exit (1);
    }
    fstat(fd, &sb);
    size = sb.st_size;
    head = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (load_file(head) < 0) {
      fprintf(stderr, "fail to read core.\n");
    }
    close(fd);
  }

  jump();

  exit (0);
}

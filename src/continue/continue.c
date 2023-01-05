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
    /* 以下の Elf_Size は(わかりにくいけど)sys/elf_generic.h で定義してある */
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
       * メモリにロードする．
       * リンカスクリプトの設定でテキスト領域の先頭に空きを作っているため，
       * 自分自身を書き換えてしまうことはない．
       * スタック領域もロードされるが，自分自身のスタックは main() の先頭で
       * 専用の場所を利用するように設定しているので，自分自身のスタックを
       * 上書きしてしまうことはない．
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

  /* 変数がレジスタに割り当てられるとまずいので static にする */
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
   * 以下の設定については setjmp()/longjmp()
   * (/usr/src/lib/libc/i386/gen)を参照．
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

  /* 各種レジスタを復旧 */
  asm volatile ("movl  0(%edx),%fs");
  asm volatile ("movl  4(%edx),%es");
  asm volatile ("movl  8(%edx),%ds");
  asm volatile ("movl 12(%edx),%edi");
  asm volatile ("movl 16(%edx),%esi");
  asm volatile ("movl 20(%edx),%ebp");
/*asm volatile ("movl 24(%edx),%isp");    */ /* アセンブル不可 */
  asm volatile ("movl 28(%edx),%ebx");
/*asm volatile ("movl 32(%edx),%edx");    */ /* 最後に行う */
  asm volatile ("movl 36(%edx),%ecx");
/*asm volatile ("movl 40(%edx),%eax");    */ /* 最後に行う */
/*asm volatile ("movl 44(%edx),%trapno"); */ /* アセンブル不可 */
/*asm volatile ("movl 48(%edx),%err");    */ /* アセンブル不可 */
/*asm volatile ("movl 52(%edx),%eip");    */ /* 最後に行う */
/*asm volatile ("movl 56(%edx),%cs");     */ /* 不正な命令 */
/*asm volatile ("movl 60(%edx),%eflags"); */ /* アセンブル不可 */
/*asm volatile ("movl 64(%edx),%esp");    */ /* 最後に行う */
  asm volatile ("movl 68(%edx),%ss");
  asm volatile ("movl 72(%edx),%gs");

  asm volatile ("movl 64(%edx),%esp"); /* スタックポインタ設定 */
  asm volatile ("pushl 52(%edx)");     /* 実行再開アドレスをスタックに設定 */
  asm volatile ("movl 40(%edx),%eax");
  asm volatile ("movl 32(%edx),%edx");

  /* ret を実行すると，スタックから戻り番地を読み込み，そこにジャンプする */
  asm volatile ("ret");
#endif

  /* ここには来ない */
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
   * コアダンプのロード時にはスタックもロードされる．そのままロードすると，
   * 自分自身が使用中のスタックを上書きしてしまうことになる．
   * よってスタック用の領域を別に確保し，そちらを利用する．
   * (上方伸長なので，お尻のほうから利用する)
   * main() のローカル変数はすでにスタック上にあるため，前もってそのぶんの
   * 空きがなければならないので，余裕を見て256バイトのパディングをする．
   * ここでスタックポインタが変化するので，これより前にローカル変数の
   * 値を設定していると，値が壊れるので注意！
   */
  stackp = stack + sizeof(stack) - 256;
  asm volatile ("movl %0,%%esp" :: "m"(stackp)); /* スタックポインタを設定 */

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

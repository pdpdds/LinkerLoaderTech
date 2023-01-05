% readelf -a sample_static
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 09 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - FreeBSD
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0x80480b8
  Start of program headers:          52 (bytes into file)
  Start of section headers:          47536 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         3
  Size of section headers:           40 (bytes)
  Number of section headers:         16
  Section header string table index: 13

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .init             PROGBITS        080480ac 0000ac 00000b 00  AX  0   0  4
  [ 2] .text             PROGBITS        080480b8 0000b8 0089ab 00  AX  0   0  4
  [ 3] .fini             PROGBITS        08050a64 008a64 000006 00  AX  0   0  4
  [ 4] .rodata           PROGBITS        08050a80 008a80 00130c 00   A  0   0 32
  [ 5] .data             PROGBITS        08052da0 009da0 000f70 00  WA  0   0 32
  [ 6] .eh_frame         PROGBITS        08053d10 00ad10 000004 00  WA  0   0  4
  [ 7] .ctors            PROGBITS        08053d14 00ad14 000008 00  WA  0   0  4
  [ 8] .dtors            PROGBITS        08053d1c 00ad1c 000008 00  WA  0   0  4
  [ 9] .bss              NOBITS          08053d40 00ad40 000870 00  WA  0   0 32
  [10] .comment          PROGBITS        00000000 00ad40 00084f 00      0   0  1
  [11] .note             NOTE            00000000 00b58f 0003ac 00      0   0  1
  [12] .note.ABI-tag     NOTE            08048094 000094 000018 00   A  0   0  4
  [13] .shstrtab         STRTAB          00000000 00b93b 000075 00      0   0  1
  [14] .symtab           SYMTAB          00000000 00bc30 000d80 10     15  2c  4
  [15] .strtab           STRTAB          00000000 00c9b0 0007da 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x000000 0x08048000 0x08048000 0x09d8c 0x09d8c R E 0x1000
  LOAD           0x009da0 0x08052da0 0x08052da0 0x00f84 0x01810 RW  0x1000
  NOTE           0x000094 0x08048094 0x08048094 0x00018 0x00018 R   0x4

 Section to Segment mapping:
  Segment Sections...
   00     .init .text .fini .rodata .note.ABI-tag 
   01     .data .eh_frame .ctors .dtors .bss 
   02     .note.ABI-tag 

There is no dynamic segment in this file.

There are no relocations in this file.

There are no unwind sections in this file.

Symbol table '.symtab' contains 216 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 080480ac     0 SECTION LOCAL  DEFAULT    1 
     2: 080480b8     0 SECTION LOCAL  DEFAULT    2 
     3: 08050a64     0 SECTION LOCAL  DEFAULT    3 
     4: 08050a80     0 SECTION LOCAL  DEFAULT    4 
     5: 08052da0     0 SECTION LOCAL  DEFAULT    5 
     6: 08053d10     0 SECTION LOCAL  DEFAULT    6 
     7: 08053d14     0 SECTION LOCAL  DEFAULT    7 
     8: 08053d1c     0 SECTION LOCAL  DEFAULT    8 
     9: 08053d40     0 SECTION LOCAL  DEFAULT    9 
    10: 00000000     0 SECTION LOCAL  DEFAULT   10 
    11: 00000000     0 SECTION LOCAL  DEFAULT   11 
    12: 08048094     0 SECTION LOCAL  DEFAULT   12 
    13: 00000000     0 SECTION LOCAL  DEFAULT   13 
    14: 00000000     0 SECTION LOCAL  DEFAULT   14 
    15: 00000000     0 SECTION LOCAL  DEFAULT   15 
    16: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    17: 08048150     0 NOTYPE  LOCAL  DEFAULT    2 gcc2_compiled.
    18: 08052da4     0 OBJECT  LOCAL  DEFAULT    5 p.3
    19: 08053d1c     0 OBJECT  LOCAL  DEFAULT    8 __DTOR_LIST__
    20: 08052da8     0 OBJECT  LOCAL  DEFAULT    5 completed.4
    21: 08048150     0 FUNC    LOCAL  DEFAULT    2 __do_global_dtors_aux
    22: 08053d10     0 OBJECT  LOCAL  DEFAULT    6 __EH_FRAME_BEGIN__
    23: 080481a4     0 FUNC    LOCAL  DEFAULT    2 fini_dummy
    24: 08053d40    24 OBJECT  LOCAL  DEFAULT    9 object.11
    25: 080481ac     0 FUNC    LOCAL  DEFAULT    2 frame_dummy
    26: 080481d0     0 FUNC    LOCAL  DEFAULT    2 init_dummy
    27: 08052dac     0 OBJECT  LOCAL  DEFAULT    5 force_to_data
    28: 08053d14     0 OBJECT  LOCAL  DEFAULT    7 __CTOR_LIST__
    29: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    30: 080509f0     0 NOTYPE  LOCAL  DEFAULT    2 gcc2_compiled.
    31: 080509f0     0 FUNC    LOCAL  DEFAULT    2 __do_global_ctors_aux
    32: 08053d18     0 OBJECT  LOCAL  DEFAULT    7 __CTOR_END__
    33: 08050a18     0 FUNC    LOCAL  DEFAULT    2 init_dummy
    34: 08053d10     0 OBJECT  LOCAL  DEFAULT    5 force_to_data
    35: 08053d20     0 OBJECT  LOCAL  DEFAULT    8 __DTOR_END__
    36: 08053d10     0 OBJECT  LOCAL  DEFAULT    6 __FRAME_END__
    37: 00000000     0 FILE    LOCAL  DEFAULT  ABS main.c
    38: 080481d8     0 NOTYPE  LOCAL  DEFAULT    2 gcc2_compiled.
    39: 00000000     0 FILE    LOCAL  DEFAULT  ABS sample.c
    40: 08048254     0 NOTYPE  LOCAL  DEFAULT    2 gcc2_compiled.
    41: 08052db0     4 OBJECT  LOCAL  DEFAULT    5 value
    42: 08048254   146 FUNC    LOCAL  DEFAULT    2 func
    43: 08053d58     4 OBJECT  LOCAL  DEFAULT    9 bssvalue
    44: 0804fd10     5 FUNC    GLOBAL DEFAULT    2 _flockfile_stub
    45: 08050780     0 FUNC    GLOBAL DEFAULT    2 strcpy
    46: 0804fe20     0 FUNC    GLOBAL DEFAULT    2 _getpid
    47: 0804fd80     0 FUNC    WEAK   DEFAULT    2 __syscall
    48: 08053038     4 OBJECT  GLOBAL DEFAULT    5 __stdoutp
    49: 0804afb0   119 FUNC    GLOBAL DEFAULT    2 __divdi3
    50: 0804fdf8     0 FUNC    WEAK   DEFAULT    2 ioctl
    51: 0804fd30     0 FUNC    GLOBAL DEFAULT    2 __exit
    52: 08048458    29 FUNC    GLOBAL DEFAULT    2 printf
    53: 0804fda8     0 FUNC    WEAK   DEFAULT    2 getdtablesize
    54: 0804f7fc    11 FUNC    GLOBAL DEFAULT    2 cfgetospeed
    55: 0804f654    67 FUNC    GLOBAL DEFAULT    2 __sseek
    56: 0804dab4    25 FUNC    GLOBAL DEFAULT    2 __sinit
    57: 0804fc84    25 FUNC    GLOBAL DEFAULT    2 sigemptyset
    58: 0804f8e0    26 FUNC    GLOBAL DEFAULT    2 __tcdrain
    59: 080482e8    54 FUNC    GLOBAL DEFAULT    2 extfunc
    60: 0804fd80     0 FUNC    GLOBAL DEFAULT    2 ___syscall
    61: 08053034     4 OBJECT  GLOBAL DEFAULT    5 __stdinp
    62: 0804da9c    21 FUNC    GLOBAL DEFAULT    2 _cleanup
    63: 0804fdd0     0 FUNC    WEAK   DEFAULT    2 munmap
    64: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _DYNAMIC
    65: 0804fd18     5 FUNC    GLOBAL DEFAULT    2 _flockfile_debug_stub
    66: 0804dc24  1016 FUNC    GLOBAL DEFAULT    2 __qdivrem
    67: 0804fd18     5 FUNC    WEAK   DEFAULT    2 _flockfile_debug
    68: 0804fd04    10 FUNC    GLOBAL DEFAULT    2 __error_unthreaded
    69: 0804f258   145 FUNC    GLOBAL DEFAULT    2 getenv
    70: 080545a8     4 OBJECT  GLOBAL DEFAULT    9 errno
    71: 0805308c     0 NOTYPE  GLOBAL DEFAULT    5 .curbrk
    72: 0805003c   293 FUNC    GLOBAL DEFAULT    2 __monetary_load_locale
    73: 0804fe20     0 FUNC    WEAK   DEFAULT    2 getpid
    74: 0804f4d0     0 FUNC    GLOBAL DEFAULT    2 memcpy
    75: 08053064     8 OBJECT  GLOBAL DEFAULT    5 __infinity
    76: 0805303c     4 OBJECT  GLOBAL DEFAULT    5 __stderrp
    77: 0804fde4     0 FUNC    WEAK   DEFAULT    2 readlink
    78: 0804fd94     0 FUNC    GLOBAL DEFAULT    2 _select
    79: 0804fd6c     0 FUNC    WEAK   DEFAULT    2 utrace
    80: 0804f8fc   110 FUNC    GLOBAL DEFAULT    2 tcflush
    81: 0804f874   106 FUNC    GLOBAL DEFAULT    2 tcsendbreak
    82: 0804ef68   253 FUNC    GLOBAL DEFAULT    2 malloc
    83: 0804e074    34 FUNC    GLOBAL DEFAULT    2 isatty
    84: 0804f808    11 FUNC    GLOBAL DEFAULT    2 cfgetispeed
    85: 08050524     0 FUNC    GLOBAL DEFAULT    2 _fstat
    86: 08051cf8     4 OBJECT  GLOBAL DEFAULT    4 sys_nerr
    87: 0804f8e0    26 FUNC    WEAK   DEFAULT    2 tcdrain
    88: 08053cf8     4 OBJECT  GLOBAL DEFAULT    5 __mb_cur_max
    89: 0804fd44     0 FUNC    GLOBAL DEFAULT    2 _sigaction
    90: 0804fd94     0 FUNC    WEAK   DEFAULT    2 select
    91: 0804d7dc   140 FUNC    GLOBAL DEFAULT    2 __smakebuf
    92: 0804fbc8     0 NOTYPE  GLOBAL DEFAULT    2 .cerror
    93: 0804dad0   121 FUNC    GLOBAL DEFAULT    2 fflush
    94: 0804aee8    42 FUNC    GLOBAL DEFAULT    2 __umoddi3
    95: 0804fbdc    39 FUNC    GLOBAL DEFAULT    2 lseek
    96: 0804fc04    63 FUNC    GLOBAL DEFAULT    2 sigaddset
    97: 0804f5a0    48 FUNC    GLOBAL DEFAULT    2 mmap
    98: 0804fd58     0 FUNC    GLOBAL DEFAULT    2 _sigprocmask
    99: 0804af14    34 FUNC    GLOBAL DEFAULT    2 __udivdi3
   100: 0804f37c   135 FUNC    GLOBAL DEFAULT    2 abort
   101: 08050974     0 FUNC    GLOBAL DEFAULT    2 _open
   102: 08048450     5 FUNC    GLOBAL DEFAULT    2 _spinlock_debug_stub
   103: 0804fd20     7 FUNC    WEAK   DEFAULT    2 ftrylockfile
   104: 0804fd20     7 FUNC    GLOBAL DEFAULT    2 _ftrylockfile_stub
   105: 080480ac     0 FUNC    GLOBAL DEFAULT    1 _init
   106: 08050530   505 FUNC    GLOBAL DEFAULT    2 strtol
   107: 080530a0  3156 OBJECT  GLOBAL DEFAULT    5 _DefaultRuneLocale
   108: 0804f2ec   141 FUNC    GLOBAL DEFAULT    2 __findenv
   109: 0804f824    16 FUNC    GLOBAL DEFAULT    2 cfsetispeed
   110: 0804db4c   110 FUNC    GLOBAL DEFAULT    2 __sflush
   111: 0804fdbc     0 FUNC    GLOBAL DEFAULT    2 _madvise
   112: 0804bc50  2851 FUNC    GLOBAL DEFAULT    2 strtod
   113: 0804b05c    37 FUNC    GLOBAL DEFAULT    2 isinf
   114: 08052dac     4 OBJECT  GLOBAL DEFAULT    5 extvalue
   115: 0804fa90     0 FUNC    WEAK   DEFAULT    2 write
   116: 08054580     4 OBJECT  GLOBAL DEFAULT    9 environ
   117: 08054590     4 OBJECT  GLOBAL DEFAULT    9 malloc_options
   118: 08050524     0 FUNC    WEAK   DEFAULT    2 fstat
   119: 0804fe0c     0 FUNC    WEAK   DEFAULT    2 kill
   120: 08050834     0 FUNC    GLOBAL DEFAULT    2 strcat
   121: 08054594     4 OBJECT  GLOBAL DEFAULT    9 __cleanup
   122: 0804d868   151 FUNC    GLOBAL DEFAULT    2 __swhatbuf
   123: 08053d04     4 OBJECT  GLOBAL DEFAULT    5 __nlocale_changed
   124: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __deregister_frame_info
   125: 0804fdbc     0 FUNC    WEAK   DEFAULT    2 madvise
   126: 080545b0     0 NOTYPE  GLOBAL DEFAULT  ABS end
   127: 08050450   204 FUNC    GLOBAL DEFAULT    2 __fix_locale_grouping_str
   128: 0804fdd0     0 FUNC    GLOBAL DEFAULT    2 _munmap
   129: 0804f814    16 FUNC    GLOBAL DEFAULT    2 cfsetospeed
   130: 0804b110     0 FUNC    GLOBAL DEFAULT    2 memchr
   131: 08053d00     4 OBJECT  GLOBAL DEFAULT    5 __mlocale_changed
   132: 0804b084    54 FUNC    GLOBAL DEFAULT    2 reallocf
   133: 08052da0     4 OBJECT  GLOBAL DEFAULT    5 __progname
   134: 080480b8   151 FUNC    GLOBAL DEFAULT    2 _start
   135: 0804fd04    10 FUNC    WEAK   DEFAULT    2 __error
   136: 0804fa10    98 FUNC    GLOBAL DEFAULT    2 signal
   137: 0804faa4     0 FUNC    WEAK   DEFAULT    2 read
   138: 0804e01c    85 FUNC    GLOBAL DEFAULT    2 ___runetype
   139: 0804abd0   789 FUNC    GLOBAL DEFAULT    2 __sfvwrite
   140: 0804fd28     5 FUNC    WEAK   DEFAULT    2 funlockfile
   141: 0804f108   336 FUNC    GLOBAL DEFAULT    2 realloc
   142: 08053cf4     4 OBJECT  GLOBAL DEFAULT    5 _CurrentRuneLocale
   143: 0804b168     0 FUNC    GLOBAL DEFAULT    2 bcopy
   144: 0804fca0    25 FUNC    GLOBAL DEFAULT    2 sigfillset
   145: 0804fd28     5 FUNC    GLOBAL DEFAULT    2 _funlockfile_stub
   146: 08052f20   264 OBJECT  GLOBAL DEFAULT    5 __sF
   147: 0804d964   237 FUNC    GLOBAL DEFAULT    2 __sfp
   148: 0804fd44     0 FUNC    WEAK   DEFAULT    2 sigaction
   149: 08054588     4 OBJECT  GLOBAL DEFAULT    9 __atexit
   150: 0804f568     0 FUNC    GLOBAL DEFAULT    2 _brk
   151: 0804f5d0    61 FUNC    GLOBAL DEFAULT    2 __sread
   152: 0804fb4c     0 FUNC    GLOBAL DEFAULT    2 sbrk
   153: 08053084     4 OBJECT  GLOBAL DEFAULT    5 __isthreaded
   154: 08053d24     0 NOTYPE  GLOBAL DEFAULT  ABS __bss_start
   155: 0804f458     0 FUNC    GLOBAL DEFAULT    2 memset
   156: 080481d8   122 FUNC    GLOBAL DEFAULT    2 main
   157: 0804f848    44 FUNC    GLOBAL DEFAULT    2 cfmakeraw
   158: 08050000    24 FUNC    GLOBAL DEFAULT    2 __get_current_numeric_loc
   159: 08048450     5 FUNC    WEAK   DEFAULT    2 _spinlock_debug
   160: 0804f698    24 FUNC    GLOBAL DEFAULT    2 __sclose
   161: 0804f708    27 FUNC    GLOBAL DEFAULT    2 tcgetattr
   162: 080512a0   348 OBJECT  GLOBAL DEFAULT    4 sys_errlist
   163: 0804f6b0    85 FUNC    GLOBAL DEFAULT    2 _fwalk
   164: 0804fe2c    39 FUNC    GLOBAL DEFAULT    2 _none_init
   165: 0804da54    70 FUNC    GLOBAL DEFAULT    2 f_prealloc
   166: 080508f8     0 FUNC    GLOBAL DEFAULT    2 strcmp
   167: 0804c95c  3544 FUNC    GLOBAL DEFAULT    2 __dtoa
   168: 08050a64     0 FUNC    GLOBAL DEFAULT    3 _fini
   169: 0804d734   165 FUNC    GLOBAL DEFAULT    2 __swsetup
   170: 080545ac     4 OBJECT  GLOBAL DEFAULT    9 _PathLocale
   171: 08048320   294 FUNC    GLOBAL DEFAULT    2 atexit
   172: 0804fd10     5 FUNC    WEAK   DEFAULT    2 flockfile
   173: 0804f834    19 FUNC    GLOBAL DEFAULT    2 cfsetspeed
   174: 0804b028    52 FUNC    GLOBAL DEFAULT    2 isnan
   175: 0804fcbc    71 FUNC    GLOBAL DEFAULT    2 sigismember
   176: 08053088     0 NOTYPE  GLOBAL DEFAULT    5 .minbrk
   177: 0804febc   227 FUNC    GLOBAL DEFAULT    2 localeconv
   178: 0804fde4     0 FUNC    GLOBAL DEFAULT    2 _readlink
   179: 08053028    12 OBJECT  GLOBAL DEFAULT    5 __sglue
   180: 0804fa90     0 FUNC    GLOBAL DEFAULT    2 _write
   181: 08053d24     0 NOTYPE  GLOBAL DEFAULT  ABS _edata
   182: 080545b0     0 NOTYPE  GLOBAL DEFAULT  ABS _end
   183: 08054598    16 OBJECT  GLOBAL DEFAULT    9 _sigintr
   184: 0804f7d0    43 FUNC    GLOBAL DEFAULT    2 tcgetpgrp
   185: 0804f610    65 FUNC    GLOBAL DEFAULT    2 __swrite
   186: 0805458c     4 OBJECT  GLOBAL DEFAULT    9 __sdidinit
   187: 08050164    24 FUNC    GLOBAL DEFAULT    2 __get_current_monetary_lo
   188: 0804fab0    73 FUNC    GLOBAL DEFAULT    2 exit
   189: 0804fdf8     0 FUNC    GLOBAL DEFAULT    2 _ioctl
   190: 0804fe84    53 FUNC    GLOBAL DEFAULT    2 _none_sputrune
   191: 0804fe0c     0 FUNC    GLOBAL DEFAULT    2 _kill
   192: 0804fc44    63 FUNC    GLOBAL DEFAULT    2 sigdelset
   193: 0804f56c     0 FUNC    GLOBAL DEFAULT    2 brk
   194: 08054584     4 OBJECT  GLOBAL DEFAULT    9 extbssvalue
   195: 0804faa4     0 FUNC    GLOBAL DEFAULT    2 _read
   196: 0804af38   118 FUNC    GLOBAL DEFAULT    2 __moddi3
   197: 0804fd30     0 FUNC    WEAK   DEFAULT    2 _exit
   198: 08050974     0 FUNC    WEAK   DEFAULT    2 open
   199: 08048448     5 FUNC    GLOBAL DEFAULT    2 _spinlock_stub
   200: 080509d4     0 FUNC    GLOBAL DEFAULT    2 strchr
   201: 0804ffa0    93 FUNC    GLOBAL DEFAULT    2 __numeric_load_locale
   202: 08048448     5 FUNC    WEAK   DEFAULT    2 _spinlock
   203: 0804fe54    46 FUNC    GLOBAL DEFAULT    2 _none_sgetrune
   204: 0804fda8     0 FUNC    GLOBAL DEFAULT    2 _getdtablesize
   205: 0804f724   136 FUNC    GLOBAL DEFAULT    2 tcsetattr
   206: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __register_frame_info
   207: 0804fd6c     0 FUNC    GLOBAL DEFAULT    2 _utrace
   208: 0804fa7c     0 FUNC    WEAK   DEFAULT    2 close
   209: 08048758  7211 FUNC    GLOBAL DEFAULT    2 vfprintf
   210: 0804f7ac    35 FUNC    GLOBAL DEFAULT    2 tcsetpgrp
   211: 0804fa7c     0 FUNC    GLOBAL DEFAULT    2 _close
   212: 0804f96c   163 FUNC    GLOBAL DEFAULT    2 tcflow
   213: 0804f068   158 FUNC    GLOBAL DEFAULT    2 free
   214: 0804fd58     0 FUNC    WEAK   DEFAULT    2 sigprocmask
   215: 0805017c   671 FUNC    GLOBAL DEFAULT    2 __part_load_locale

No version information found in this file.
% 

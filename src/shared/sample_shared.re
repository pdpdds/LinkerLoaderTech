% readelf -a sample_shared
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
  Entry point address:               0x8048448
  Start of program headers:          52 (bytes into file)
  Start of section headers:          2316 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         6
  Size of section headers:           40 (bytes)
  Number of section headers:         25
  Section header string table index: 22

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .interp           PROGBITS        080480f4 0000f4 000019 00   A  0   0  1
  [ 2] .note.ABI-tag     NOTE            08048110 000110 000018 00   A  0   0  4
  [ 3] .hash             HASH            08048128 000128 000098 04   A  4   0  4
  [ 4] .dynsym           DYNSYM          080481c0 0001c0 000130 10   A  5   1  4
  [ 5] .dynstr           STRTAB          080482f0 0002f0 0000cb 00   A  0   0  1
  [ 6] .rel.bss          REL             080483bc 0003bc 000010 08   A  4  13  4
  [ 7] .rel.plt          REL             080483cc 0003cc 000020 08   A  4   9  4
  [ 8] .init             PROGBITS        080483ec 0003ec 00000b 00  AX  0   0  4
  [ 9] .plt              PROGBITS        080483f8 0003f8 000050 04  AX  0   0  4
  [10] .text             PROGBITS        08048448 000448 0001cc 00  AX  0   0  4
  [11] .fini             PROGBITS        08048614 000614 000006 00  AX  0   0  4
  [12] .rodata           PROGBITS        0804861a 00061a 000054 00   A  0   0  1
  [13] .data             PROGBITS        08049670 000670 00000c 00  WA  0   0  4
  [14] .eh_frame         PROGBITS        0804967c 00067c 000004 00  WA  0   0  4
  [15] .dynamic          DYNAMIC         08049680 000680 0000c0 08  WA  5   0  4
  [16] .ctors            PROGBITS        08049740 000740 000008 00  WA  0   0  4
  [17] .dtors            PROGBITS        08049748 000748 000008 00  WA  0   0  4
  [18] .got              PROGBITS        08049750 000750 00001c 04  WA  0   0  4
  [19] .bss              NOBITS          0804976c 00076c 000024 00  WA  0   0  4
  [20] .comment          PROGBITS        00000000 00076c 0000a0 00      0   0  1
  [21] .note             NOTE            00000000 00080c 000050 00      0   0  1
  [22] .shstrtab         STRTAB          00000000 00085c 0000ae 00      0   0  1
  [23] .symtab           SYMTAB          00000000 000cf4 000440 10     24  30  4
  [24] .strtab           STRTAB          00000000 001134 0001b3 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  PHDR           0x000034 0x08048034 0x08048034 0x000c0 0x000c0 R E 0x4
  INTERP         0x0000f4 0x080480f4 0x080480f4 0x00019 0x00019 R   0x1
      [Requesting program interpreter: /usr/libexec/ld-elf.so.1]
  LOAD           0x000000 0x08048000 0x08048000 0x0066e 0x0066e R E 0x1000
  LOAD           0x000670 0x08049670 0x08049670 0x000fc 0x00120 RW  0x1000
  DYNAMIC        0x000680 0x08049680 0x08049680 0x000c0 0x000c0 RW  0x4
  NOTE           0x000110 0x08048110 0x08048110 0x00018 0x00018 R   0x4

 Section to Segment mapping:
  Segment Sections...
   00     
   01     .interp 
   02     .interp .note.ABI-tag .hash .dynsym .dynstr .rel.bss .rel.plt .init .plt .text .fini .rodata 
   03     .data .eh_frame .dynamic .ctors .dtors .got .bss 
   04     .dynamic 
   05     .note.ABI-tag 

Dynamic segment at offset 0x680 contains 19 entries:
  Tag        Type                         Name/Value
 0x00000001 (NEEDED)                     Shared library: [libsample.so.1]
 0x00000001 (NEEDED)                     Shared library: [libc.so.4]
 0x0000000f (RPATH)                      Library rpath: [.]
 0x0000000c (INIT)                       0x80483ec
 0x0000000d (FINI)                       0x8048614
 0x00000004 (HASH)                       0x8048128
 0x00000005 (STRTAB)                     0x80482f0
 0x00000006 (SYMTAB)                     0x80481c0
 0x0000000a (STRSZ)                      203 (bytes)
 0x0000000b (SYMENT)                     16 (bytes)
 0x00000015 (DEBUG)                      0x0
 0x00000003 (PLTGOT)                     0x8049750
 0x00000002 (PLTRELSZ)                   32 (bytes)
 0x00000014 (PLTREL)                     REL
 0x00000017 (JMPREL)                     0x80483cc
 0x00000011 (REL)                        0x80483bc
 0x00000012 (RELSZ)                      16 (bytes)
 0x00000013 (RELENT)                     8 (bytes)
 0x00000000 (NULL)                       0x0

Relocation section '.rel.bss' at offset 0x3bc contains 2 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0804976c  00000505 R_386_COPY        0804976c   extvalue
08049770  00001105 R_386_COPY        08049770   extbssvalue

Relocation section '.rel.plt' at offset 0x3cc contains 4 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0804975c  00000107 R_386_JUMP_SLOT   08048408   printf
08049760  00000207 R_386_JUMP_SLOT   08048418   extfunc
08049764  00000c07 R_386_JUMP_SLOT   08048428   atexit
08049768  00001007 R_386_JUMP_SLOT   08048438   exit

There are no unwind sections in this file.

Symbol table '.dynsym' contains 19 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 08048408    47 FUNC    GLOBAL DEFAULT  UND printf
     2: 08048418    73 FUNC    GLOBAL DEFAULT  UND extfunc
     3: 08049680     0 OBJECT  GLOBAL DEFAULT  ABS _DYNAMIC
     4: 080483ec     0 FUNC    GLOBAL DEFAULT    8 _init
     5: 0804976c     4 OBJECT  GLOBAL DEFAULT   19 extvalue
     6: 0804978c     4 OBJECT  GLOBAL DEFAULT   19 environ
     7: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __deregister_frame_info
     8: 08049790     0 NOTYPE  GLOBAL DEFAULT  ABS end
     9: 08049670     4 OBJECT  GLOBAL DEFAULT   13 __progname
    10: 0804976c     0 NOTYPE  GLOBAL DEFAULT  ABS __bss_start
    11: 08048614     0 FUNC    GLOBAL DEFAULT   11 _fini
    12: 08048428   332 FUNC    GLOBAL DEFAULT  UND atexit
    13: 0804976c     0 NOTYPE  GLOBAL DEFAULT  ABS _edata
    14: 08049750     0 OBJECT  GLOBAL DEFAULT  ABS _GLOBAL_OFFSET_TABLE_
    15: 08049790     0 NOTYPE  GLOBAL DEFAULT  ABS _end
    16: 08048438    91 FUNC    GLOBAL DEFAULT  UND exit
    17: 08049770     4 OBJECT  GLOBAL DEFAULT   19 extbssvalue
    18: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __register_frame_info

Symbol table '.symtab' contains 68 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 080480f4     0 SECTION LOCAL  DEFAULT    1 
     2: 08048110     0 SECTION LOCAL  DEFAULT    2 
     3: 08048128     0 SECTION LOCAL  DEFAULT    3 
     4: 080481c0     0 SECTION LOCAL  DEFAULT    4 
     5: 080482f0     0 SECTION LOCAL  DEFAULT    5 
     6: 080483bc     0 SECTION LOCAL  DEFAULT    6 
     7: 080483cc     0 SECTION LOCAL  DEFAULT    7 
     8: 080483ec     0 SECTION LOCAL  DEFAULT    8 
     9: 080483f8     0 SECTION LOCAL  DEFAULT    9 
    10: 08048448     0 SECTION LOCAL  DEFAULT   10 
    11: 08048614     0 SECTION LOCAL  DEFAULT   11 
    12: 0804861a     0 SECTION LOCAL  DEFAULT   12 
    13: 08049670     0 SECTION LOCAL  DEFAULT   13 
    14: 0804967c     0 SECTION LOCAL  DEFAULT   14 
    15: 08049680     0 SECTION LOCAL  DEFAULT   15 
    16: 08049740     0 SECTION LOCAL  DEFAULT   16 
    17: 08049748     0 SECTION LOCAL  DEFAULT   17 
    18: 08049750     0 SECTION LOCAL  DEFAULT   18 
    19: 0804976c     0 SECTION LOCAL  DEFAULT   19 
    20: 00000000     0 SECTION LOCAL  DEFAULT   20 
    21: 00000000     0 SECTION LOCAL  DEFAULT   21 
    22: 00000000     0 SECTION LOCAL  DEFAULT   22 
    23: 00000000     0 SECTION LOCAL  DEFAULT   23 
    24: 00000000     0 SECTION LOCAL  DEFAULT   24 
    25: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    26: 080484e0     0 NOTYPE  LOCAL  DEFAULT   10 gcc2_compiled.
    27: 08049674     0 OBJECT  LOCAL  DEFAULT   13 p.3
    28: 08049748     0 OBJECT  LOCAL  DEFAULT   17 __DTOR_LIST__
    29: 08049678     0 OBJECT  LOCAL  DEFAULT   13 completed.4
    30: 080484e0     0 FUNC    LOCAL  DEFAULT   10 __do_global_dtors_aux
    31: 0804967c     0 OBJECT  LOCAL  DEFAULT   14 __EH_FRAME_BEGIN__
    32: 08048534     0 FUNC    LOCAL  DEFAULT   10 fini_dummy
    33: 08049774    24 OBJECT  LOCAL  DEFAULT   19 object.11
    34: 0804853c     0 FUNC    LOCAL  DEFAULT   10 frame_dummy
    35: 08048560     0 FUNC    LOCAL  DEFAULT   10 init_dummy
    36: 0804967c     0 OBJECT  LOCAL  DEFAULT   13 force_to_data
    37: 08049740     0 OBJECT  LOCAL  DEFAULT   16 __CTOR_LIST__
    38: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    39: 080485e4     0 NOTYPE  LOCAL  DEFAULT   10 gcc2_compiled.
    40: 080485e4     0 FUNC    LOCAL  DEFAULT   10 __do_global_ctors_aux
    41: 08049744     0 OBJECT  LOCAL  DEFAULT   16 __CTOR_END__
    42: 0804860c     0 FUNC    LOCAL  DEFAULT   10 init_dummy
    43: 0804967c     0 OBJECT  LOCAL  DEFAULT   13 force_to_data
    44: 0804974c     0 OBJECT  LOCAL  DEFAULT   17 __DTOR_END__
    45: 0804967c     0 OBJECT  LOCAL  DEFAULT   14 __FRAME_END__
    46: 00000000     0 FILE    LOCAL  DEFAULT  ABS main.c
    47: 08048568     0 NOTYPE  LOCAL  DEFAULT   10 gcc2_compiled.
    48: 08048408    47 FUNC    GLOBAL DEFAULT  UND printf
    49: 08048418    73 FUNC    GLOBAL DEFAULT  UND extfunc
    50: 08049680     0 OBJECT  GLOBAL DEFAULT  ABS _DYNAMIC
    51: 080483ec     0 FUNC    GLOBAL DEFAULT    8 _init
    52: 0804976c     4 OBJECT  GLOBAL DEFAULT   19 extvalue
    53: 0804978c     4 OBJECT  GLOBAL DEFAULT   19 environ
    54: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __deregister_frame_info
    55: 08049790     0 NOTYPE  GLOBAL DEFAULT  ABS end
    56: 08049670     4 OBJECT  GLOBAL DEFAULT   13 __progname
    57: 08048448   151 FUNC    GLOBAL DEFAULT   10 _start
    58: 0804976c     0 NOTYPE  GLOBAL DEFAULT  ABS __bss_start
    59: 08048568   122 FUNC    GLOBAL DEFAULT   10 main
    60: 08048614     0 FUNC    GLOBAL DEFAULT   11 _fini
    61: 08048428   332 FUNC    GLOBAL DEFAULT  UND atexit
    62: 0804976c     0 NOTYPE  GLOBAL DEFAULT  ABS _edata
    63: 08049750     0 OBJECT  GLOBAL DEFAULT  ABS _GLOBAL_OFFSET_TABLE_
    64: 08049790     0 NOTYPE  GLOBAL DEFAULT  ABS _end
    65: 08048438    91 FUNC    GLOBAL DEFAULT  UND exit
    66: 08049770     4 OBJECT  GLOBAL DEFAULT   19 extbssvalue
    67: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __register_frame_info

Histogram for bucket list length (total of 17 buckets):
 Length  Number     % of total  Coverage
      0  6          ( 35.3%)
      1  5          ( 29.4%)     27.8%
      2  5          ( 29.4%)     83.3%
      3  1          (  5.9%)    100.0%

No version information found in this file.
% 

% readelf -a sample.o
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 09 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - FreeBSD
  ABI Version:                       0
  Type:                              REL (Relocatable file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0x0
  Start of program headers:          0 (bytes into file)
  Start of section headers:          516 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           0 (bytes)
  Number of program headers:         0
  Size of section headers:           40 (bytes)
  Number of section headers:         11
  Section header string table index: 8

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        00000000 000034 0000cc 00  AX  0   0  4
  [ 2] .rel.text         REL             00000000 000510 0000a0 08      9   1  4
  [ 3] .data             PROGBITS        00000000 000100 000008 00  WA  0   0  4
  [ 4] .bss              NOBITS          00000000 000108 000004 00  WA  0   0  4
  [ 5] .note             NOTE            00000000 000108 000014 00      0   0  1
  [ 6] .rodata           PROGBITS        00000000 00011c 000077 00   A  0   0  1
  [ 7] .comment          PROGBITS        00000000 000193 000028 00      0   0  1
  [ 8] .shstrtab         STRTAB          00000000 0001bb 000047 00      0   0  1
  [ 9] .symtab           SYMTAB          00000000 0003bc 000100 10     10   c  4
  [10] .strtab           STRTAB          00000000 0004bc 000051 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

There are no program headers in this file.

There is no dynamic segment in this file.

Relocation section '.rel.text' at offset 0x510 contains 20 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0000000a  00000701 R_386_32          00000000   .rodata
0000000f  00000d02 R_386_PC32        00000000   printf
0000001a  00000c01 R_386_32          00000000   extvalue
00000020  00000701 R_386_32          00000000   .rodata
00000025  00000d02 R_386_PC32        00000000   printf
00000030  00000e01 R_386_32          00000004   extbssvalue
00000036  00000701 R_386_32          00000000   .rodata
0000003b  00000d02 R_386_PC32        00000000   printf
00000046  00000301 R_386_32          00000000   .data
0000004c  00000701 R_386_32          00000000   .rodata
00000051  00000d02 R_386_PC32        00000000   printf
0000005c  00000401 R_386_32          00000000   .bss
00000062  00000701 R_386_32          00000000   .rodata
00000067  00000d02 R_386_PC32        00000000   printf
00000073  00000c01 R_386_32          00000000   extvalue
0000007c  00000e01 R_386_32          00000004   extbssvalue
00000082  00000301 R_386_32          00000000   .data
00000088  00000401 R_386_32          00000000   .bss
0000009e  00000701 R_386_32          00000000   .rodata
000000a3  00000d02 R_386_PC32        00000000   printf

There are no unwind sections in this file.

Symbol table '.symtab' contains 16 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000000     0 FILE    LOCAL  DEFAULT  ABS sample.c
     2: 00000000     0 SECTION LOCAL  DEFAULT    1 
     3: 00000000     0 SECTION LOCAL  DEFAULT    3 
     4: 00000000     0 SECTION LOCAL  DEFAULT    4 
     5: 00000000     0 NOTYPE  LOCAL  DEFAULT    1 gcc2_compiled.
     6: 00000004     4 OBJECT  LOCAL  DEFAULT    3 value
     7: 00000000     0 SECTION LOCAL  DEFAULT    6 
     8: 00000000   146 FUNC    LOCAL  DEFAULT    1 func
     9: 00000000     4 OBJECT  LOCAL  DEFAULT    4 bssvalue
    10: 00000000     0 SECTION LOCAL  DEFAULT    5 
    11: 00000000     0 SECTION LOCAL  DEFAULT    7 
    12: 00000000     4 OBJECT  GLOBAL DEFAULT    3 extvalue
    13: 00000000     0 NOTYPE  GLOBAL DEFAULT  UND printf
    14: 00000004     4 OBJECT  GLOBAL DEFAULT  COM extbssvalue
    15: 00000094    54 FUNC    GLOBAL DEFAULT    1 extfunc

No version information found in this file.
% 

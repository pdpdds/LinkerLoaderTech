% readelf -S -r -s rasm.o
There are 11 section headers, starting at offset 0x124:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        00000000 000034 000054 00  AX  0   0  4
  [ 2] .rel.text         REL             00000000 000498 000038 08      9   1  4
  [ 3] .data             PROGBITS        00000000 000088 000008 00  WA  0   0  4
  [ 4] .bss              NOBITS          00000000 000090 000008 00  WA  0   0  4
  [ 5] .note             NOTE            00000000 000090 000014 00      0   0  1
  [ 6] .rodata           PROGBITS        00000000 0000a4 00000e 00   A  0   0  1
  [ 7] .comment          PROGBITS        00000000 0000b2 000028 00      0   0  1
  [ 8] .shstrtab         STRTAB          00000000 0000da 000047 00      0   0  1
  [ 9] .symtab           SYMTAB          00000000 0002dc 000140 10     10   f  4
  [10] .strtab           STRTAB          00000000 00041c 00007a 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

Relocation section '.rel.text' at offset 0x498 contains 7 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0000000c  00000f01 R_386_32          00000000   extvalue
00000012  00001001 R_386_32          00000000   extbssvalue
0000001b  00000301 R_386_32          00000000   .data
00000021  00000401 R_386_32          00000000   .bss
00000037  00001202 R_386_PC32        00000000   extfunc
00000042  00001301 R_386_32          00000004   string
00000046  00000b01 R_386_32          00000000   .rodata

Symbol table '.symtab' contains 20 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000000     0 FILE    LOCAL  DEFAULT  ABS rasm.c
     2: 00000000     0 SECTION LOCAL  DEFAULT    1 
     3: 00000000     0 SECTION LOCAL  DEFAULT    3 
     4: 00000000     0 SECTION LOCAL  DEFAULT    4 
     5: 00000000     0 NOTYPE  LOCAL  DEFAULT    1 gcc2_compiled.
     6: 00000000     4 OBJECT  LOCAL  DEFAULT    3 dummy_value
     7: 00000004     4 OBJECT  LOCAL  DEFAULT    3 value
     8: 00000000     5 FUNC    LOCAL  DEFAULT    1 dummy_func
     9: 00000008    38 FUNC    LOCAL  DEFAULT    1 func
    10: 00000004     4 OBJECT  LOCAL  DEFAULT    4 bssvalue
    11: 00000000     0 SECTION LOCAL  DEFAULT    6 
    12: 00000000     4 OBJECT  LOCAL  DEFAULT    4 dummy_bssvalue
    13: 00000000     0 SECTION LOCAL  DEFAULT    5 
    14: 00000000     0 SECTION LOCAL  DEFAULT    7 
    15: 00000000     0 NOTYPE  GLOBAL DEFAULT  UND extvalue
    16: 00000000     0 NOTYPE  GLOBAL DEFAULT  UND extbssvalue
    17: 00000030    34 FUNC    GLOBAL DEFAULT    1 main
    18: 00000000     0 NOTYPE  GLOBAL DEFAULT  UND extfunc
    19: 00000004     4 OBJECT  GLOBAL DEFAULT  COM string
% 

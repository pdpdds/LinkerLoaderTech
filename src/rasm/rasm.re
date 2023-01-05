% readelf -S -s rasm
There are 24 section headers, starting at offset 0x7d0:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0

        ...(ÃæÎ¬)...

  [ 8] .plt              PROGBITS        0804831c 00031c 000030 04  AX  0   0  4
  [ 9] .text             PROGBITS        0804834c 00034c 0001b8 00  AX  0   0  4
  [10] .fini             PROGBITS        08048504 000504 000006 00  AX  0   0  4
  [11] .rodata           PROGBITS        0804850a 00050a 00000f 00   A  0   0  1
  [12] .data             PROGBITS        0804951c 00051c 00001c 00  WA  0   0  4
  [13] .eh_frame         PROGBITS        08049538 000538 000004 00  WA  0   0  4
  [14] .dynamic          DYNAMIC         0804953c 00053c 000098 08  WA  5   0  4
  [15] .ctors            PROGBITS        080495d4 0005d4 000008 00  WA  0   0  4
  [16] .dtors            PROGBITS        080495dc 0005dc 000008 00  WA  0   0  4
  [17] .got              PROGBITS        080495e4 0005e4 000014 04  WA  0   0  4
  [18] .bss              NOBITS          080495f8 0005f8 000030 00  WA  0   0  4
  [19] .comment          PROGBITS        00000000 0005f8 0000c8 00      0   0  1

        ...(ÃæÎ¬)...

Symbol table '.symtab' contains 78 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 080480f4     0 SECTION LOCAL  DEFAULT    1 
     2: 08048110     0 SECTION LOCAL  DEFAULT    2 

        ...(ÃæÎ¬)...

    45: 00000000     0 FILE    LOCAL  DEFAULT  ABS rasm.c
    46: 0804846c     0 NOTYPE  LOCAL  DEFAULT    9 gcc2_compiled.
    47: 08049528     4 OBJECT  LOCAL  DEFAULT   12 dummy_value
    48: 0804952c     4 OBJECT  LOCAL  DEFAULT   12 value
    49: 0804846c     5 FUNC    LOCAL  DEFAULT    9 dummy_func
    50: 08048474    38 FUNC    LOCAL  DEFAULT    9 func
    51: 08049614     4 OBJECT  LOCAL  DEFAULT   18 bssvalue
    52: 08049610     4 OBJECT  LOCAL  DEFAULT   18 dummy_bssvalue
    53: 00000000     0 FILE    LOCAL  DEFAULT  ABS rasm2.c
    54: 080484c0     0 NOTYPE  LOCAL  DEFAULT    9 gcc2_compiled.
    55: 080484c8    10 FUNC    GLOBAL DEFAULT    9 extfunc
    56: 0804953c     0 OBJECT  GLOBAL DEFAULT  ABS _DYNAMIC
    57: 0804961c     4 OBJECT  GLOBAL DEFAULT   18 string
    58: 08048310     0 FUNC    GLOBAL DEFAULT    7 _init
    59: 08049534     4 OBJECT  GLOBAL DEFAULT   12 extvalue
    60: 08049618     4 OBJECT  GLOBAL DEFAULT   18 environ
    61: 080484c0     5 FUNC    GLOBAL DEFAULT    9 dummy_extfunc
    62: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __deregister_frame_info
    63: 08049628     0 NOTYPE  GLOBAL DEFAULT  ABS end
    64: 0804951c     4 OBJECT  GLOBAL DEFAULT   12 __progname
    65: 0804834c   151 FUNC    GLOBAL DEFAULT    9 _start
    66: 080495f8     0 NOTYPE  GLOBAL DEFAULT  ABS __bss_start
    67: 0804849c    34 FUNC    GLOBAL DEFAULT    9 main
    68: 08048504     0 FUNC    GLOBAL DEFAULT   10 _fini
    69: 0804832c   332 FUNC    GLOBAL DEFAULT  UND atexit
    70: 08049620     4 OBJECT  GLOBAL DEFAULT   18 dummy_extbssvalue
    71: 08049530     4 OBJECT  GLOBAL DEFAULT   12 dummy_extvalue
    72: 080495f8     0 NOTYPE  GLOBAL DEFAULT  ABS _edata
    73: 080495e4     0 OBJECT  GLOBAL DEFAULT  ABS _GLOBAL_OFFSET_TABLE_
    74: 08049628     0 NOTYPE  GLOBAL DEFAULT  ABS _end
    75: 0804833c    91 FUNC    GLOBAL DEFAULT  UND exit
    76: 08049624     4 OBJECT  GLOBAL DEFAULT   18 extbssvalue
    77: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __register_frame_info
% 

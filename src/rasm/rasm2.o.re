% readelf -S -s rasm2.o
There are 9 section headers, starting at offset 0xc8:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        00000000 000034 000014 00  AX  0   0  4
  [ 2] .data             PROGBITS        00000000 000048 000008 00  WA  0   0  4
  [ 3] .bss              NOBITS          00000000 000050 000000 00  WA  0   0  4
  [ 4] .note             NOTE            00000000 000050 000014 00      0   0  1
  [ 5] .comment          PROGBITS        00000000 000064 000028 00      0   0  1
  [ 6] .shstrtab         STRTAB          00000000 00008c 00003b 00      0   0  1
  [ 7] .symtab           SYMTAB          00000000 000230 0000e0 10      8   8  4
  [ 8] .strtab           STRTAB          00000000 000310 000064 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

Symbol table '.symtab' contains 14 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000000     0 FILE    LOCAL  DEFAULT  ABS rasm2.c
     2: 00000000     0 SECTION LOCAL  DEFAULT    1 
     3: 00000000     0 SECTION LOCAL  DEFAULT    2 
     4: 00000000     0 SECTION LOCAL  DEFAULT    3 
     5: 00000000     0 NOTYPE  LOCAL  DEFAULT    1 gcc2_compiled.
     6: 00000000     0 SECTION LOCAL  DEFAULT    4 
     7: 00000000     0 SECTION LOCAL  DEFAULT    5 
     8: 00000000     4 OBJECT  GLOBAL DEFAULT    2 dummy_extvalue
     9: 00000004     4 OBJECT  GLOBAL DEFAULT    2 extvalue
    10: 00000000     5 FUNC    GLOBAL DEFAULT    1 dummy_extfunc
    11: 00000008    10 FUNC    GLOBAL DEFAULT    1 extfunc
    12: 00000004     4 OBJECT  GLOBAL DEFAULT  COM dummy_extbssvalue
    13: 00000004     4 OBJECT  GLOBAL DEFAULT  COM extbssvalue
% 

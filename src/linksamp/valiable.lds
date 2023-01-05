SECTIONS
{
  . = 0x08048000 + SIZEOF_HEADERS;
  .text   : { *(.text) }
  .rodata : { *(.rodata) }
  .data   : {
    cvalue = .;
    BYTE(1)
    . = ALIGN(2);
    svalue = .;
    SHORT(12345)
    . = ALIGN(4);
    lvalue = .;
    LONG(87654321)
    lvalue2 = .;
    . += 4;
    *(.data)
  }
  .bss    : { *(.bss)  }
}

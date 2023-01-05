SECTIONS
{
  . = 0x08048000 + SIZEOF_HEADERS;
  .text   : { *(.text) }
  .rodata : { *(.rodata) }
  .data   : {
    cvalue = .;
    BYTE(1)
    . = ALIGN(4);
    svalue = .;
    SHORT(0x1234)
    FILL(0x55555555)
    . = ALIGN(4);
    lvalue = .;
    FILL(0x99999999)
    . += 4;
    lvalue2 = .;
    . += 4;
    *(.data)
  } =0xaaaaaaaa
  .bss    : { *(.bss)  }
}

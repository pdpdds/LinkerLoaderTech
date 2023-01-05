SECTIONS
{
  . = 0x08048000 + SIZEOF_HEADERS;
  .text   : { stext = .;           *(.text) }
  .rodata : { PROVIDE(srdata = .); *(.rodata) }
  .data   : { PROVIDE(sdata  = .); *(.data) }
  .bss    : { *(.bss)  }
}

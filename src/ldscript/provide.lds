SECTIONS
{
  . = 0x08048000 + SIZEOF_HEADERS;
  .text   : { PROVIDE(stext  = .); *(.text)   PROVIDE(etext  = .); }
  .rodata : { PROVIDE(srdata = .); *(.rodata) PROVIDE(erdata = .); }
  .data   : { PROVIDE(sdata  = .); *(.data)   PROVIDE(edata  = .); }
  .bss    : { PROVIDE(sbss   = .); *(.bss)    PROVIDE(ebss   = .); }
}

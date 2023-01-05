SECTIONS
{
  value = 0x12345678;
  . = 0x08048000 + SIZEOF_HEADERS;
  .text   : AT(value) { stext  = .; *(.text)   etext  = .; }
  .rodata :           { srdata = .; *(.rodata) erdata = .; }
  .data   :           { sdata  = .; *(.data)   edata  = .; }
  .bss    :           { sbss   = .; *(.bss)    ebss   = .; }
}

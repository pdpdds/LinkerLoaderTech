SECTIONS
{
  . = 0x08048000 + SIZEOF_HEADERS;
  .text   : { *(.text)   }
  .rodata : { *(.rodata) }
  .data   : { *(.data)   }
  .bss    : { *(.bss)    }
}


OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

MEMORY{
  ipl_body : org = 0x7C00, len = 0x1FE
}

SECTIONS{
  .text  : { *(.text)  } > ipl_body
  .data  : { *(.data .rdata .rodata*) } > ipl_body
  .bss   : { *(.bss)   } > ipl_body

  /* ����Ȃ��Z�N�V�����͂��ׂč�� */
  /DISCARD/ : { *(*)}
}

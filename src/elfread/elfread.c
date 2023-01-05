#include <stdio.h>
#include <elf.h>

int main()
{
  Elf_Ehdr *ehdr;

  ehdr = (Elf_Ehdr *)0x08048000;

  printf("0x%02x%c%c%c\n",
	 ehdr->e_ident[EI_MAG0],
	 ehdr->e_ident[EI_MAG1],
	 ehdr->e_ident[EI_MAG2],
	 ehdr->e_ident[EI_MAG3]);
  exit (0);
}

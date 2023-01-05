#ifndef __FBSD_TO_LINUX__
#define __FBSD_TO_LINUX__

typedef Elf32_Ehdr Elf_Ehdr;
typedef Elf32_Phdr Elf_Phdr;
typedef Elf32_Shdr Elf_Shdr;
typedef Elf32_Sym  Elf_Sym;
typedef Elf32_Rel  Elf_Rel;
typedef Elf32_Rela Elf_Rela;

typedef Elf32_Word Elf_Size;
typedef Elf32_Addr Elf_Addr;
typedef Elf32_Nhdr Elf_Note;

#define ELF_ST_TYPE(v) ELF32_ST_TYPE(v)
#define ELF_ST_BIND(v) ELF32_ST_BIND(v)
#define ELF_R_SYM(v)   ELF32_R_SYM(v)
#define ELF_R_TYPE(v)  ELF32_R_TYPE(v)

#define ELF_CLASS      ELFCLASS32
#define ELF_DATA       ELFDATA2LSB
#define ELF_TARG_CLASS ELFCLASS32
#define ELF_TARG_DATA  ELFDATA2LSB
#define ELF_TARG_MACH  EM_386
#define ELF_TARG_VER   1

#define IS_ELF(ehdr) \
	((ehdr).e_ident[EI_MAG0] == ELFMAG0 && \
	 (ehdr).e_ident[EI_MAG1] == ELFMAG1 && \
	 (ehdr).e_ident[EI_MAG2] == ELFMAG2 && \
	 (ehdr).e_ident[EI_MAG3] == ELFMAG3)

#endif

#include <elf.h>

struct obj {
  char *filename;
  char *address;
};

Elf_Shdr *get_section(Elf_Ehdr *ehdr, char *name);
int search_symbol(struct obj objs[], char *name, struct obj *obj);
int relocate_common_symbol(Elf_Ehdr *ehdr);
int check_ehdr(Elf_Ehdr *ehdr);
int link_objs(struct obj objs[]);

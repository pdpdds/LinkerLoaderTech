/*
 * Header prepended to each a.out file.
 * only manipulate the a_midmag field via the
 * N_SETMAGIC/N_GET{MAGIC,MID,FLAG} macros in a.out.h
 */

struct exec {
     unsigned long	a_midmag;	/* flags<<26 | mid<<16 | magic */
     unsigned long	a_text;		/* text segment size */
     unsigned long	a_data;		/* initialized data size */
     unsigned long	a_bss;		/* uninitialized data size */
     unsigned long	a_syms;		/* symbol table size */
     unsigned long	a_entry;	/* entry point */
     unsigned long	a_trsize;	/* text relocation size */
     unsigned long	a_drsize;	/* data relocation size */
};
#define a_magic a_midmag /* XXX Hack to work with current kern_execve.c */

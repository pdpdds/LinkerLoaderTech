	.file	"stack_sample.c"
	.version	"01.01"
gcc2_compiled.:
.text
	.p2align 2,0x90
.globl func
		.type		 func,@function
func:
	pushl %ebp
	movl %esp,%ebp
	xorl %eax,%eax
	jmp .L6
	.p2align 2,0x90
.L6:
	leave
	ret
.Lfe1:
		.size		 func,.Lfe1-func
	.p2align 2,0x90
.globl main
		.type		 main,@function
main:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	addl $-8,%esp
	pushl $2
	pushl $1
	call func
	addl $16,%esp
	movl %eax,%eax
	pushl %eax
	call exit
	addl $16,%esp
	.p2align 2,0x90
.L7:
	leave
	ret
.Lfe2:
		.size		 main,.Lfe2-main
	.ident	"GCC: (GNU) c 2.95.4 20020320 [FreeBSD]"

	.globl	syscall
syscall:
	pop	%ecx
	pop	%eax
	push	%ecx
	int	$0x80
	push	%ecx
	ret

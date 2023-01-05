/*
 * C library -- _setjmp, _longjmp
 *
 *	longjmp(a,v)
 * will generate a "return(v)" from the last call to
 *	setjmp(a)
 * by restoring registers from the environment 'a'.
 * The previous signal state is restored.
 */

#include "DEFS.h"
#include "SYS.h"

ENTRY(setjmp)
	movl	4(%esp),%ecx
	PIC_PROLOGUE
	leal	28(%ecx), %eax
	pushl	%eax			/* (sigset_t*)oset */
	pushl	$0			/* (sigset_t*)set  */
	pushl	$1			/* SIG_BLOCK       */
	call	PIC_PLT(CNAME(sigprocmask))
	addl	$12,%esp
	PIC_EPILOGUE
	movl	4(%esp),%ecx
	movl	0(%esp),%edx
	movl	%edx, 0(%ecx)
	movl	%ebx, 4(%ecx)
	movl	%esp, 8(%ecx)
	movl	%ebp,12(%ecx)
	movl	%esi,16(%ecx)
	movl	%edi,20(%ecx)
	fnstcw	24(%ecx)
	xorl	%eax,%eax
	ret

#ifndef _THREAD_SAFE
.weak CNAME(longjmp);
.set CNAME(longjmp),CNAME(__longjmp);
#endif
ENTRY(__longjmp)
	movl	4(%esp),%edx
	PIC_PROLOGUE
	pushl	$0			/* (sigset_t*)oset */
	leal	28(%edx), %eax
	pushl	%eax			/* (sigset_t*)set  */
	pushl	$3			/* SIG_SETMASK     */
	call	PIC_PLT(CNAME(sigprocmask))
	addl	$12,%esp
	PIC_EPILOGUE
	movl	4(%esp),%edx
	movl	8(%esp),%eax
	movl	0(%edx),%ecx
	movl	4(%edx),%ebx
	movl	8(%edx),%esp
	movl	12(%edx),%ebp
	movl	16(%edx),%esi
	movl	20(%edx),%edi
	fninit
	fldcw	24(%edx)
	testl	%eax,%eax
	jnz	1f
	incl	%eax
1:	movl	%ecx,0(%esp)
	ret

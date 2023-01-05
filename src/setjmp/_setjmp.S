/*
 * C library -- _setjmp, _longjmp
 *
 *	_longjmp(a,v)
 * will generate a "return(v)" from the last call to
 *	_setjmp(a)
 * by restoring registers from the environment 'a'.
 * The previous signal state is NOT restored.
 */

#include "DEFS.h"

ENTRY(_setjmp)
	movl	4(%esp),%eax
	movl	0(%esp),%edx
	movl	%edx, 0(%eax)		/* rta */
	movl	%ebx, 4(%eax)
	movl	%esp, 8(%eax)
	movl	%ebp,12(%eax)
	movl	%esi,16(%eax)
	movl	%edi,20(%eax)
	fnstcw	24(%eax)
	xorl	%eax,%eax
	ret

#ifdef _THREAD_SAFE
ENTRY(___longjmp)
#else
ALTENTRY(___longjmp)
ENTRY(_longjmp)
#endif
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

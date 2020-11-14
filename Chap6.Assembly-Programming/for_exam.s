	.file	"for_exam.c"
	.section	.rodata
.LC0:
	.string	"a = %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	subl	%eax, %esp
	movl	$0, i
.L2:
	cmpl	$9, i
	jg	.L3
	movl	i, %eax
	addl	%eax, a
	incl	i
	jmp	.L2
.L3:
	subl	$8, %esp
	pushl	a
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.comm	i,4,4
	.comm	a,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

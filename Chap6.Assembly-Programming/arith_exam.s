	.file	"arith_exam.c"
.globl a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	2
.globl b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	3
	.section	.rodata
.LC0:
	.string	"c = %d, d = %d"
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
	movl	b, %edx
	movl	a, %eax
	subl	%edx, %eax
	movl	%eax, c
	movl	b, %edx
	movl	b, %eax
	sall	$3, %eax
	subl 	%edx, %eax
	movl	%eax, d
	subl	$4, %esp
	pushl	d
	pushl	c
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.comm	c,4,4
	.comm	d,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

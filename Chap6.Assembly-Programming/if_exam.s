	.file	"if_exam.c"
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
.globl d
	.align 4
	.type	d, @object
	.size	d, 4
d:
	.long	6
	.section	.rodata
.LC0:
	.string	"c = %d, d = %d\n"
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
	movl	a, %eax
	cmpl	b, %eax
	jle	.L2
	movl	a, %eax
	movl	%eax, c
	jmp	.L3
.L2:
	movl	b, %eax
	movl	%eax, c
.L3:
	cmpl	$0, d
	jne	.L4
	orl	$3, d
	jmp	.L5
.L4:
	andl	$-4, d
.L5:
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
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

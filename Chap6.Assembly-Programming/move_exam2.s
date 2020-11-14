	.file	"move_exam2.c"
	.section	.rodata
.LC0:
	.string	"c = %c\n"
.LC1:
	.string	"b = %d\n"
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
	movl	$64, a1
	movl	a1, %eax
	incl	%eax
	movl	%eax, a2
	movl	a1, %eax
	movw	%ax, b
	movl	a2, %eax
	movb	%al, c
	movl	$7, d+8
	subl	$8, %esp
	movsbl	c,%eax
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	movswl	b,%eax
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.comm	a1,4,4
	.comm	a2,4,4
	.comm	b,2,2
	.comm	c,1,1
	.comm	d,40,32
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

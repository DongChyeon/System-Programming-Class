	.file	"func_exam.c"
	.text
.globl func1
	.type	func1, @function
func1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$777, -4(%ebp)
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	leave
	ret
	.size	func1, .-func1
	.section	.rodata
.LC0:
	.string	"g = %d\n"
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
	movl	$888, h
	subl	$8, %esp
	pushl	$222
	pushl	$111
	call	func
	addl	$16, %esp
	movl	%eax, g
	movl	$999, h
	subl	$8, %esp
	pushl	g
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.comm	g,4,4
	.comm	h,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

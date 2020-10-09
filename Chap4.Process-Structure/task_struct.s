	.file	"task_struct.c"
	.section	.rodata
.LC0:
	.string	"func2 local : \n\t%p, \n\t%p\n"
	.text
.globl func2
	.type	func2, @function
func2:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	leal	-8(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	ret
	.size	func2, .-func2
	.section	.rodata
.LC1:
	.string	"func1 local : \n\t%p, \n\t%p\n"
	.text
.globl func1
	.type	func1, @function
func1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	leal	-8(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	call	func2
	leave
	ret
	.size	func1, .-func1
	.section	.rodata
.LC2:
	.string	"main local : \n\t%p, \n\t%p\n"
.LC3:
	.string	"dynamic : \n\t%p\n"
.LC4:
	.string	"global : \n\t%p, \n\t%p\n"
.LC5:
	.string	"functions : \n\t%p, \n\t%p, \n\t%p\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	subl	%eax, %esp
	leal	-8(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	call	func1
	movl	$16, (%esp)
	call	malloc
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	$glob2, 8(%esp)
	movl	$glob1, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	$func2, 12(%esp)
	movl	$func1, 8(%esp)
	movl	$main, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.comm	glob1,4,4
	.comm	glob2,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

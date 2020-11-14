	.file	"caller.c"
	.text
.globl swap_and
	.type	swap_and, @function
swap_and:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %edx
	movl	-8(%ebp), %eax
	movl	%eax, (%edx)
	movl	12(%ebp), %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	movl	-8(%ebp), %eax
	addl	-4(%ebp), %eax
	leave
	ret
	.size	swap_and, .-swap_and
.globl caller
	.type	caller, @function
caller:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$534, -4(%ebp)
	movl	$1057, -8(%ebp)
	subl	$8, %esp
	leal	-8(%ebp), %eax
	pushl	%eax
	leal	-4(%ebp), %eax
	pushl	%eax
	call	swap_add
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %edx
	movl	-4(%ebp), %eax
	subl	%edx, %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	imull	-16(%ebp), %eax
	leave
	ret
	.size	caller, .-caller
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

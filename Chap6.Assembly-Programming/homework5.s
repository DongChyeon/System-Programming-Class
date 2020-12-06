	.file	"homework5.c"
	.text
.globl isPrime
	.type	isPrime, @function
isPrime:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	cmpl	$1, 8(%ebp)
	jg	.L2
	movl	$0, -8(%ebp)
	jmp	.L1
.L2:
	movl	8(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L3
	movl	$1, -8(%ebp)
	jmp	.L1
.L3:
	movl	$0, -8(%ebp)
.L1:
	movl	-8(%ebp), %eax
	leave
	ret
	.size	isPrime, .-isPrime
	.section	.rodata
.LC0:
	.string	"%d "
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
	movl	$1, -4(%ebp)
.L11:
	cmpl	$100, -4(%ebp)
	jg	.L12
	subl	$12, %esp
	pushl	-4(%ebp)
	call	isPrime
	addl	$16, %esp
	testb	%al, %al
	je	.L13
	subl	$8, %esp
	pushl	-4(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
.L13:
	leal	-4(%ebp), %eax
	incl	(%eax)
	jmp	.L11
.L12:
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

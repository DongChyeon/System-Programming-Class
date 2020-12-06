	.file	"prime_number.c"
	.section	.rodata
.LC0:
	.string	"%d\353\212\224 \354\206\214\354\210\230\354\236\205\353\213\210\353\213\244.\n"
	.text
.globl asm_prime_number
	.type	asm_prime_number, @function
asm_prime_number:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
.L2:
	movl	12(%ebp), %eax
	incl	%eax
	cmpl	-8(%ebp), %eax
	jle	.L1
	movl	$0, -4(%ebp)
	movl	$2, -12(%ebp)
.L5:
	movl	-12(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jge	.L6
	movl	-8(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	%edx, %eax
	movl	-16(%ebp), %ecx
	cltd
	idivl	(%ecx)
	testl	%edx, %edx
	jne	.L7
	leal	-4(%ebp), %eax
	incl	(%eax)
.L7:
	leal	-12(%ebp), %eax
	incl	(%eax)
	jmp	.L5
.L6:
	cmpl	$0, -4(%ebp)
	jne	.L4
	subl	$8, %esp
	pushl	-8(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
.L4:
	leal	-8(%ebp), %eax
	incl	(%eax)
	jmp	.L2
.L1:
	leave
	ret
	.size	asm_prime_number, .-asm_prime_number
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
	subl	$8, %esp
	pushl	$100
	pushl	$1
	call	asm_prime_number
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-5)"

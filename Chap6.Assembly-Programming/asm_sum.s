	.text
.global asm_sum
asm_sum:
	pushl	%ebp
	movl	%esp, %ebp
	subl 	$4, %esp

	movl 	8(%ebp), %ecx
	movl	$0, -4(%ebp)
L1:
	cmpl	$0, %ecx
	je	L2
	addl	%ecx, -4(%ebp)
	decl	%ecx
	jmp	L1
L2:
	movl	-4(%ebp), %eax
	leave	
	ret

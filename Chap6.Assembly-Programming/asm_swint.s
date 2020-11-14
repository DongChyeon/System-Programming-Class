	.data
W_buf:
	.string "Hello world\n"
W_size:
	.long 12
P_arg:
	.string "Result = %d\n"

	.text
.global main
main:
	pushl	%ebp
	movl	%esp, %ebp
	
	movl	$1, %ebx
	movl	$W_buf, %ecx
	movl 	W_size, %edx

	movl	$4, %eax
	int	$0x80

	pushl	%eax
	pushl	$P_arg
	call	printf
	addl	$8, %esp

	leave
	ret

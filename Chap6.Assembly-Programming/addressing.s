	.data
	.size	array, 40
array:
	.long 2
	.long 3
	.long 4
	.long 3
	.long 7
	.long 6
	.long 9
	.long 2
	.long 8
	.long 9
P_arg:
	.string "Sum of array = %d\n"
	.text
.global main
	.type main, @function
main:
	pushl %ebp
	movl %esp, %ebp
	subl $8, %esp

	movl $0, %ecx
	movl $0, %eax
	movl $array, %ebx
LOOP:
	cmpl $9, %ecx
	jg LOOP_CUT
	addl 0(%ebx, %ecx, 4), %eax
	addl $1, %ecx
	jmp LOOP
LOOP_CUT:
	pushl %eax
	pushl $P_arg
	call printf
	addl $8, %esp
	leave
	ret

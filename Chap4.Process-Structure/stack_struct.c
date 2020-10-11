/* stack_struct.c : stack structure analysis */
#include <stdio.h>

int func2(int x, int y) {
	int f2_local1 = 21, f2_local2 = 22;
	int *pointer;
	
	printf("func2 local : \t%p, \t%p, \t%p\n", &f2_local1, &f2_local2, &pointer);
	pointer = &f2_local1;

	printf("\t%p \t%d\n", (pointer), *(pointer));
	printf("\t%p \t%d\n", (pointer-1), *(pointer-1));
	printf("\t%p \t%d\n", (pointer+3), *(pointer+3));
	
	*(pointer+4) = 333;
	printf("\ty=%d\n", y);
	return 222;
}

void func1() {
	int ret_val, f1_local1 = 11, f1_local2 = 12;

	ret_val = func2(111, 112);
}

main() {
	func1();
}

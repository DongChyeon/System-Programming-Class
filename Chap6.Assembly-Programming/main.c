#include <stdio.h>

main() {
	int a;
	
	a = asm_sum(5);
	printf("sum = %d\n", a);

	a = asm_sum(10);
	printf("sum = %d\n", a);
}

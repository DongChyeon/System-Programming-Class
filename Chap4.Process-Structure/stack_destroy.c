/* stack_destroy.c: anlaysis stack structure, by donghyeon, kimdonghyun90766@gmail.com */
#include <stdio.h>

void f1() {
	int i;
	printf("In func1\n");
}

void f2() {
	int j, *ptr;
	printf("f2 local : \t%p, \t%p\n", &j, &ptr);
	printf("In func2\n");

	ptr = &j;
	*(ptr+2) = f1;
}

void f3() {
	printf("Before invoke f2()\n");
	f2();
	printf("After invoke f2()\n");
}

main() {
	f3();
}

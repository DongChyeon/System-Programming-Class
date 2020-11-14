#include <stdio.h>

int main(void) {
	int a = 0x12345678;
	unsigned char *p_a;

	p_a = (unsigned char *)&a;
	printf("p_a[0] = %x\n", p_a[0]);
	printf("p_a[3] = %x\n", p_a[3]);
}

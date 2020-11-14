#include <stdio.h>

int a = 2, b = 3;
int c, d = 0x6;

main() {
	if (a > b) c = a;
	else c = b;
	
	if (d == 0) d |= 0x3;
	else d &= ~(0x3);

	printf("c = %d, d = %d\n", c, d);
}

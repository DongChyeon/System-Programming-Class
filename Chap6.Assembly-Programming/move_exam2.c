#include <stdio.h>

int a1, a2;
short b;
char c;
int d[10];

int main() {
	a1 = 64;
	a2 = a1 + 1;
	b = a1;
	c = a2;
	d[2] = 7;

	printf("c = %c\n", c);
	printf("b = %d\n", b);
}

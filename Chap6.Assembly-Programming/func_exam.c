#include <stdio.h>

int g, h;

int func1(int x, int y) {
	int a, b;

	a = 777;
	b = x + y;

	return b;
}

main() {
	h = 888;
	g = func(111,222);
	h = 999;
	printf("g = %d\n", g);
}

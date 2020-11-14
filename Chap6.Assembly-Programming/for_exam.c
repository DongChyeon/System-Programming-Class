#include <stdio.h>

int i;
int a;

main() {
	for (i = 0; i < 10; i++) a = a + i;
	printf("a = %d\n", a);
}

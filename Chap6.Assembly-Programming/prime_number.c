#include <stdio.h>

void asm_prime_number(int x, int y) {
	int count, i, j;
	for (i = x; i < y + 1; i++) {
		count = 0;
		for (j = 2; j < i; j++) {
			if (i % j == 0) count++;
		}
		if (count == 0) {
			printf("%d는 소수입니다.\n", i);
		}
	}
}

main() {
	asm_prime_number(1, 100);
}

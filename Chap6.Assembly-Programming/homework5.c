#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
	int i;
	
	if (n <= 1) return false;

	if (n % 2 == 0) return true;
	else return false;

	for (i = 1; i < sqrt(n); i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main() {
	int i;

	for (i = 1; i < 101; i++) {
		if (isPrime(i)) printf("%d ", i);
	}	
	return 0;
}

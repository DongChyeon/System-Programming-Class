#include <stdio.h>

struct Test {
	int a;
	double d1;
	char ch;
	double d2;
};

int main() {
	Test test;
	printf("Size of Test is %d\n", sizeof(test));
}

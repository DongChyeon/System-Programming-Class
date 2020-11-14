#include <stdio.h>
#include <stdlib.h>

int a = 10;

void *func() {
	a++;
	printf("pid = %d\n", getpid());
}

int main() {
	int pid;
	
	if ((pid = fork()) == 0) {
		func();
		exit(0);
	}
	wait();
	printf("a = %d by pid = %d\n", a, getpid());
}

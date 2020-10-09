/* fork_test2.c : accessing variables, by donghyeon, kimdonghyun90766@gmail.com */
/* Note : This code is borrowed from "Advanced Programming in the Unix Env." */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int glob = 6;
char buf[] = "a write to stdout\n";

int main(void) {
	int var = 88;
	pid_t fork_return;

	if (write(STDOUT_FILENO, buf, sizeof(buf)) != sizeof(buf)) {
		perror("write error");
		exit(1);
	}
	printf("before fork\n");
	
	if ((fork_return = fork()) < 0) {
		perror("fork error");
		exit(1);
	} else if (fork_return == 0) {
		glob++;
		var++;
	} else {
		sleep(2);
	}
	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	exit(0);
}

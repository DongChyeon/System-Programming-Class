/* execl_test.c : execute a hello program */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	pid_t fork_return, d_pid; int exit_status = -1;

	if ((fork_return = fork()) == -1) {
		// fork error handling
	} else if (fork_return == 0) {
		execl("./hello", "./hello", (char *)0);
		printf("Child.. I'm here\n");
		exit(1);
	} else {
		d_pid = wait(&exit_status);
		printf("Parent.. I'm here\n");
		printf("exit status of process %d is %d\n", d_pid, exit_status);	}
}

/* execl_test3.c : parameter passing, Sept 11, kimdonghyun90766@gmail.com */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char *argv[]) {
	pid_t fork_return, d_pid; int exit_status;
	char *const myenv[] = {"sys programming", "is", "fun", (char *)0};

	if ((fork_return = fork()) == -1) {
		//fork error handling
	} else if (fork_return == 0) {
		execle("./execl_test2", "./execl_test2", "Hi", "DKU", (char *)0, myenv);
		printf("Child.. I'm here\n");
	} else {	// parent
		d_pid = wait(&exit_status);
		printf("exit pid = %d with status = %d\n", d_pid, WEXITSTATUS(exit_status));
	}
}

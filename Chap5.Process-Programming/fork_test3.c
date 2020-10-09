/* fork_test3.c, by donghyeon, kimdonghyun90766@gmail.com */

#include <stdio.h>
#include <sys/types.h>
main() {
	pid_t fork_return;

	fork();
	fork();
	fork();
	if (fork_return == 0) {
		printf("Child Process end\n");
	} else {
		printf("Parent Process end\n");
	}
}

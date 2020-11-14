/* fork_test.c example, by donghyeon, kimdonghyun90766gmail.com */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main() {
	pid_t fork_return;
	printf("Hello, my pid is %d\n", getpid());

	if ((fork_return = fork()) < 0) {
		perror("fork error");
		exit(1);
	} else if (fork_return == 0) {
		printf("chlid : pid = %d, ppid = %d\n", getpid(), getppid());
	} else {
		wait();
		printf("parent : I created chlid with pid=%d\n", fork_return);
	}

	printf("Bye, my pid is %d\n", getpid());
}

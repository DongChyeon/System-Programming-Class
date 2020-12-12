#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 4

main() {
	int fork_return1, fork_return2, fdin, fdout, read_size;
	char *gcc_exec[] = { "gcc", "-o", "hello.out", "hello.c", 0 };
	char *ls_exec[] = { "ls", "-l", 0 };	
	char buf[MAX_BUF];

	fork_return1 = fork();

	if (fork_return1 == -1) {
		printf("fork error\n");
		return;
	} else if (fork_return1 == 0) {
		printf("pid : %d\n", getppid());
		execvp(gcc_exec[0], gcc_exec);
	} else {
		wait();
	}

	fork_return2 = fork();
	
	if (fork_return2 == -1) {
		printf("fork error\n");
		return;
	} else if (fork_return2 == 0) {
		fdin = open("ls.out", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fdin, STDOUT_FILENO);
		close(fdin);
		execvp(ls_exec[0], ls_exec);
	} else {
		wait();
		
		fdin = open("ls.out", O_RDONLY);
		fdout = open("/dev/pts/2", O_WRONLY);
		while (1) {
			read_size = read(fdin, buf, MAX_BUF);
			if (read_size == 0) break;
			write(fdout, buf, read_size);
		}
		close(fdin);
		close(fdout);
	}	
	return;
}

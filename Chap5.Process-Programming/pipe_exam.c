/* Pipe example */
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd[2];
	char bufc[16], bufp[16];
	int read_size = 0;

	pipe(fd);
	if (fork() == 0) {
		write(fd[1], "Thank you", 10);
		sleep(1);
		read_size = read(fd[0], bufc, 16);
		bufc[read_size] = '\0';
		printf("%s by pid %d\n", bufc, getpid());
		exit(0);
	} else {
		read_size = read(fd[0], bufp, 16);
		bufp[read_size] = '\0';
		printf("%s by pid %d\n", bufp, getpid());
		write(fd[1], "My pleasure", 12);
		wait();
		close(fd[0]); close(fd[1]);
	}
}

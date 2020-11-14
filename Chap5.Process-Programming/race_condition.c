#include <sys/types.h>
#include <unistd.h>

static void charatatime(char *str) {
	int i;

	for (; *str; str++) {
		for (i = 0; i < 1000; i++);
		write(STDOUT_FILENO, str, 1);
	}
}

int main(void) {
	pid_t pid;

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		charatatime("output from child\n");
	} else {
		charatatime("output from parent\n");
	}
}

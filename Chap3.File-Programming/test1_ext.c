/* file_test1_ext.c: read from a file and display them, by donghyeon, kimdonghyeon90766@gmail.com */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 16
char fname[] = "alphabet.txt";

int main() {
	int fd, read_size, write_size;
	char buf[MAX_BUF];

	fd = open(fname, O_RDONLY);
	if (fd < 0) {
		printf("Can't open %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	read_size = read(fd, buf, MAX_BUF);
	if (read_size < 0) {
		printf("Can't read from file %s, size = %d\n", fname, read_size);
		exit(-1);
	}
	write_size = write(STDOUT_FILENO, buf, read_size);
	close(fd);
}

/* file_create.c: create a new file, by donghyeon. kimdonghyun90766@gmail.com */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64
char fname[] = "newfile.txt";
char dummy_data[] = "abcdefg\n";

int main() {
	int fd, write_size, read_size;
	char buf[MAX_BUF];

	fd = open(fname, O_RDWR | O_CREAT | O_EXCL, 0664);
	if (fd < 0) {
		printf("Can't create %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	write_size = write(fd, dummy_data, sizeof(dummy_data));
	printf("write_size = %d\n", write_size);
	close(fd);

	fd = open(fname, O_RDONLY);
	read_size = read(fd, buf, MAX_BUF);
	printf("read_size = %d\n", read_size);
	write_size = write(STDOUT_FILENO, buf, read_size);
	close(fd);
}

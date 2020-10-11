/* file_redirection.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64

int main(int argc, char *argv[]) {
	int fd, fd1, read_size, write_size;
	char buf[MAX_BUF];

	if (argc != 4) {
		printf("USAGE: %s input_file_name \">\" output_file_name\n", argv[0]);
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);	

	// for redirection. (eg. "mycat inputfile.txt > outputfile.txt")
	// close(STDOUT_FILENO);
	fd1 = open(argv[3], O_RDWR | O_CREAT, 0641);
	dup2(fd1, STDOUT_FILENO);
	// redirection end
	
	while(1) {
		read_size = read(fd, buf, MAX_BUF);
		if (read_size == 0) break;
		write_size = write(STDOUT_FILENO, buf, read_size);
	}
	close(fd);
}

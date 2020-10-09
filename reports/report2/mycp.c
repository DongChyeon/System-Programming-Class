/* mycp program, by donghyeon, kimdonghyun90766@gmail.com */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#define MAX_BUF 64

int main(int argc, char *argv[]) {
	int fdin, fdout, read_size;
	char buf[MAX_BUF];

	struct stat fdin_info;
	struct utimbuf timebuf;

	if (argc != 3) {
		printf("USAGE : %s original_file copied_file\n", argv[0]);
		exit(-1);
	}

	fdin = open(argv[1], O_RDONLY);
	if (fdin < 0) {
		printf("Cant open %s file with errno with %d\n", argv[1], fdin);
	}

	if (fstat(fdin, &fdin_info) == -1) {
		printf("Can't load %s file's stat.", argv[1]);
		exit(-1);
	}
	timebuf.actime = fdin_info.st_atime;
	timebuf.modtime = fdin_info.st_mtime;	

	fdout = open(argv[2], O_RDWR | O_CREAT | O_EXCL);
	if (fdout < 0) {
		printf("Can't create %s file with errno %d\n", argv[2], errno);
		exit(-1);
	}

	while (1) {
		read_size = read(fdin, buf, MAX_BUF);
		if (read_size == 0) break;
		write(fdout, buf, read_size);
	}
	fchmod(fdout, fdin_info.st_mode); 
	utime(argv[2], &timebuf); 
	
	close(fdin);
	close(fdout);
}

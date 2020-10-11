/* file_device.c */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_BUF 4

char fname[] = "test.txt";
char tmp_data[] = "abcdefghijklmn\n";

int main() {
	int fd, size;
	char buf[MAX_BUF];

	fd = open(fname, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd, tmp_data, sizeof(tmp_data));
	close(fd);

	fd = open(fname, O_RDONLY);
	lseek(fd, 5, SEEK_SET);
	size = read(fd, buf, MAX_BUF); 
	close(fd);

	fd = open("dev/pts/5", O_WRONLY);
	write(fd, buf, MAX_BUF);
	close(fd);
}

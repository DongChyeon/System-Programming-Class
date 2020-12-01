#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void target_job(int loopsize) {
	int i;
	for (i = 0; i < loopsize; i++);
}

int main(int argc, char *argv[]) {
	int i, loop = 0;

	struct timeval stime, etime, gap;
	
	if (argc == 2) {
		loop = atoi(argv[1]);
		gettimeofday(&stime, NULL);
		target_job(loop);
		gettimeofday(&etime, NULL);
		gap.tv_sec = etime.tv_sec - stime.tv_sec;
		gap.tv_usec = etime.tv_usec - stime.tv_usec;
		if (gap.tv_usec < 0) {
			gap.tv_sec = gap.tv_sec - 1;
			gap.tv_usec = gap.tv_usec + 1000000;
		}
		printf("Elapsed time %ldsec : %ldusec\n", gap.tv_sec, gap.tv_usec);
	}
	else
		printf("Usage : command loop_size\n");
} 	

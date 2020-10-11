/* execl_test2.c : printing argv[] and env[] */
#include <stdio.h>
int main(int argc, char *argv[], char *envp[]) {
	int i;
	for (i = 0; argv[i]; i++) printf("arg %d = %s\n", i, argv[i]);
	for (i = 0; envp[i]; i++) printf("env %d = %s\n", i, envp[i]);
}

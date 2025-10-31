#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main (void) {
	printf("Parent ID: %id\n", getpid());

	pid_t pid = fork();
	if (pid < 0) {
		fprintf(stderr, "fork failed: %s\n", strerror(errno));
		return 1;
	}

	if (pid == 0) {
		printf("Child PID: % (PPID: %d)\n", getpid(), getpid());
	}

}
 

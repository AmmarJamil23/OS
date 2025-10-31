#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Hello! My pid is %d \n ", getpid());
	printf("I will sleep for 30 seconds... \n");
	sleep(30);
	printf("Woek up! Exiting now. \n");
	return  0;

}

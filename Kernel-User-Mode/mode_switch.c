#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Running in User Mode (PID: %d)\n", getpid());
	write(1, "Making a system call...\n",24); //syscall to kernel.
	printf("Back in User Moode again!\n");
	return 0;

}

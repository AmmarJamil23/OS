#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Hello from process %d\n", getpid());
	sleep(5);
	return 0;
}

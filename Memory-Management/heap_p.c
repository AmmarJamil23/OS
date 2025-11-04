#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	printf("Initial program break: %p\n", sbrk(0));
	
	void *block = malloc(1024 * 1024);
	
	printf("After malloc: %p\n", sbrk(0));
	
	free(block);
	printf("After free: %p\n", sbrk(0));
	
	return 0;


}

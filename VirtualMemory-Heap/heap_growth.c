#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf("INitial program break: %p\n", sbrk(0));
	
	void *block1 = malloc(1024 * 1024);
	printf("After 1st malloc : %p\n", sbrk(0));
	
	void *block2 = malloc(1024 * 1024);
	printf("After 2nd malloc: %p\n", sbrk(0));
	
	free(block1);
	free(block2);
	
	printf("After free(): %p\n", sbrk(0));
	
	return 0;

}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd = open ("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0) {
		perror("open failed");
		return 1;
	}
	
	const char *msg = "Operating Systems are powerful! More bytes hehe\n";
	ssize_t bytes_written = write(fd, msg, strlen(msg));
	
	if (bytes_written < 0) {
		perror("write failed");
		close(fd);
		return 1;
	}
	
	printf("Wrote %zd bytes to example.txt\n", bytes_written);
	close(fd);
	return 0;

}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fd[2];
	if (pipe(fd) == -1){
		perror("pipe failed");
		exit(1);
	}
	
	pid_t pid = fork();
	if (pid < 0){
		perror("fork failed");
		exit(1);
	}
	
	if (pid == 0){
	//child write message to pipe
	close(fd[0]);
	const char *msg = "Hello from child!";
	write(fd[1], msg, strlen(msg) + 1);
	close (fd[1]);
	} 
	else {
	close (fd[1]);
	char buffer[100];
	read(fd[0], buffer, sizeof(buffer));
	printf("Parent recieved: %s\n", buffer);
	close (fd[0]);
	  
	}
	return 0;
	

}

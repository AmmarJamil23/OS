#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
	printf("\nCaught signal %d (SIGINT). Cleaniing up...\n", sig);

}

int main(){
	signal(SIGINT, handle_sigint);
	printf("Press CTRL+C to send SIGINT.\n");
	while (1) sleep (1);
	return 0;

}

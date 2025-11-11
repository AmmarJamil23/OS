#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_interrupt(int sig){
	printf("\n[Interrupt] Signal %d received. Handling it...\n", sig);

}

int main(){
	signal(SIGINT, handle_interrupt);
	printf("Program running. Press CTRL+C to trigger interrupt.\n" );
	
	while(1){
		printf("Working...\n");
		sleep(2);
	}
	return 0;
}

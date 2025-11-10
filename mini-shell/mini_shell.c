// mini_shell.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void parse_input(char *input, char **args) {
    // Split input by spaces
    for (int i = 0; i < MAX_ARGS; i++) {
        args[i] = strsep(&input, " ");
        if (args[i] == NULL) break;
        if (strlen(args[i]) == 0) i--;
    }
}

int main() {
    char input[MAX_INPUT];
    char *args1[MAX_ARGS], *args[MAX_ARGS];
    int fd[2]

    while (1) {
        printf("mini-shell> ");
        fflush(stdout);

        if (!fgets(input, MAX_INPUT, stdin))
            break;

        input[strcspn(input, "\n")] = '\0'; // Remove newline

        // Handle built-in commands
        if (strcmp(input, "exit") == 0) {
         
            break;
        }
        
        char *pipe_pos = strchr(input, '|');
        if (pipe_pos){
        	*pipe_pos = '\0';
        	char *cmd1 = input;
        	char *cmd2 = pipe_pos + 1;
        	
        	parse_input(cmd1, args1);
        	parse_input(cmd2, args2);
        	
        	pipe(fd);
        	pid_t pi1 = fork();
        	
        	if (pid1 == 0){
        		
        	
        	}
        
        }
        
        
        
        
        
        
        

        if (strncmp(input, "cd ", 3) == 0) {
            char *path = input + 3;
            if (chdir(path) != 0)
                perror("cd failed");
            continue;
        }

        parse_input(input, args);

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            continue;
        }

        if (pid == 0) {
            
            if (execvp(args[0], args) == -1) {
                perror("exec failed");
                exit(1);
            }
        } else {
            
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}


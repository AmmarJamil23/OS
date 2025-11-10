
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void parse_input(char *input, char **args) {
    for (int i = 0; i < MAX_ARGS; i++) {
        args[i] = strsep(&input, " ");
        if (args[i] == NULL) break;
        if (strlen(args[i]) == 0) i--;
    }
}

int main() {
    char input[MAX_INPUT];
    char *args1[MAX_ARGS], *args2[MAX_ARGS];
    int fd[2];

    while (1) {
        printf("mini-shell> ");
        fflush(stdout);

        if (!fgets(input, MAX_INPUT, stdin)) break;
        input[strcspn(input, "\n")] = '\0'; 

        
        if (strcmp(input, "exit") == 0) break;

        
        char *pipe_pos = strchr(input, '|');
        if (pipe_pos) {
            *pipe_pos = '\0';
            char *cmd1 = input;
            char *cmd2 = pipe_pos + 1;

            parse_input(cmd1, args1);
            parse_input(cmd2, args2);

            pipe(fd);
            pid_t pid1 = fork();

            if (pid1 == 0) {
                
                close(fd[0]);
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                execvp(args1[0], args1);
                perror("exec1 failed");
                exit(1);
            }

            pid_t pid2 = fork();

            if (pid2 == 0) {
                
                close(fd[1]);
                dup2(fd[0], STDIN_FILENO);
                close(fd[0]);
                execvp(args2[0], args2);
                perror("exec2 failed");
                exit(1);
            }

            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
            continue;
        }

        
        char *redir_pos = strchr(input, '>');
        if (redir_pos) {
            *redir_pos = '\0';
            char *cmd = input;
            char *filename = redir_pos + 1;
            while (*filename == ' ') filename++;

            parse_input(cmd, args1);
            pid_t pid = fork();

            if (pid == 0) {
                int fd_out = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
                dup2(fd_out, STDOUT_FILENO);
                close(fd_out);
                execvp(args1[0], args1);
                perror("exec failed");
                exit(1);
            }
            wait(NULL);
            continue;
        }

        
        parse_input(input, args1);
        pid_t pid = fork();

        if (pid == 0) {
            execvp(args1[0], args1);
            perror("exec failed");
            exit(1);
        }

        wait(NULL);
    }

    return 0;
}


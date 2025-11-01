#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(void) {
    printf("Parent PID: %d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return 1;
    }

    if (pid == 0) {  // Child process
        printf("Child PID: %d (PPID: %d)\n", getpid(), getppid());

        // execl expects full path ("/bin/ls" not just "ls")
        execl("/bin/ls", "ls", "-l", (char *)NULL);

        // If execl() fails, this runs:
        fprintf(stderr, "exec failed: %s\n", strerror(errno));
        _exit(127);
    } else {  // Parent process
        int status = 0;
        pid_t w = waitpid(pid, &status, 0);

        if (w == -1) {
            fprintf(stderr, "waitpid failed: %s\n", strerror(errno));
            return 1;
        }

        if (WIFEXITED(status)) {
            printf("Child exited with code %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child killed by signal %d\n", WTERMSIG(status));
        }
    }

    return 0;
}


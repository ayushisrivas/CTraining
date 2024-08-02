#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2];  // File descriptors for pipe
    pid_t pid;
    char buf[30];

    // Create pipe
    if (pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {  // Parent process
        close(fd[0]);  // Close unused read end
        char *message = "Hello from parent";
        write(fd[1], message, strlen(message) + 1);  // Write message to pipe
        close(fd[1]);  // Close write end after writing
    } else {  // Child process
        close(fd[1]);  // Close unused write end
        read(fd[0], buf, sizeof(buf));  // Read from pipe
        printf("Child received: %s\n", buf);
        close(fd[0]);  // Close read end after reading
    }

    return 0;
}


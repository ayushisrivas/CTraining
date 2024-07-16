#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int pipefd[2];  // Global pipe file descriptors

void signal_handler(int signum) {
    // Signal handler for SIGUSR1
    // This function does nothing, just allows the pause() call in parent to wake up
}

int main() {
    pid_t pid;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up signal handler for SIGUSR1
    signal(SIGUSR1, signal_handler);

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        close(pipefd[0]);  // Close read end of the pipe (not used by parent)

        const char *messages[] = {
            "First message from parent",
            "Second message from parent",
            "Third message from parent"
        };
        int num_messages = sizeof(messages) / sizeof(messages[0]);

        for (int i = 0; i < num_messages; ++i) {
            // Send message to child
            if (write(pipefd[1], messages[i], strlen(messages[i]) + 1) == -1) {
                perror("Write to pipe failed");
                exit(EXIT_FAILURE);
            }

            // Wait for signal from child (SIGUSR1)
            pause();  // Parent will wait here until SIGUSR1 is received
        }

        close(pipefd[1]);  // Close write end of the pipe
        wait(NULL);  // Wait for child process to terminate
    } else {
        // Child process
        close(pipefd[1]);  // Close write end of the pipe (not used by child)

        while ((bytes_read = read(pipefd[0], buffer, BUFFER_SIZE)) > 0) {
            // Process the data received from parent
            buffer[bytes_read - 1] = '\0';  // Ensure null-terminated string
            printf("Child received: %s\n", buffer);

            // Signal parent that child is ready for next message
            kill(getppid(), SIGUSR1);
        }

        close(pipefd[0]);  // Close read end of the pipe
        exit(EXIT_SUCCESS);
    }

    return 0;
}


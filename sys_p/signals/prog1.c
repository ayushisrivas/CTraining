#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sigint_handler(int signum) {
    printf("\nCaught SIGINT signal (Ctrl+C)\n");
    printf("Press Ctrl+C again to exit.\n");
}

int main() {
    // Registering SIGINT signal handler
    signal(SIGINT, sigint_handler);

    printf("Running. Press Ctrl+C to see the message.\n");

    // Infinite loop to keep the program running
    while (1) {
        // Do nothing, just keep the program running
        sleep(1);
    }

    return 0;
}


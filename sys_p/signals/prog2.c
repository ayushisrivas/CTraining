#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sig_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nCaught SIGINT signal (Ctrl+C)\n");
        printf("Press Ctrl+C again to exit.\n");
    } else if (signum == SIGTERM) {
        printf("\nCaught SIGTERM signal\n");
        printf("Terminating the program...\n");
        // Optional: Perform cleanup before exit
        exit(0);
    }
}

int main() {
    // Registering SIGINT and SIGTERM signal handler
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    printf("Running. Press Ctrl+C to see the SIGINT message.\n");

    // Infinite loop to keep the program running
    while (1) {
        // Do nothing, just keep the program running
        sleep(1);
    }

    return 0;
}


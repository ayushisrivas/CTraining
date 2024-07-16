#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Ignore SIGINT signal
    signal(SIGINT, SIG_IGN);

    printf("Running. Press Ctrl+C (SIGINT) to see that it's ignored.\n");

    // Infinite loop to keep the program running
    while (1) {
        // Do nothing, just keep the program running
        sleep(1);
    }

    return 0;
}

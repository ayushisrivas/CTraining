#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
void sigusr1_handler(int signum) {
    printf("Received SIGUSR1 signal (%d)\n", signum);
}
 
int main() {
    // Register SIGUSR1 handler
    signal(SIGUSR1, sigusr1_handler);
 
    printf("Waiting for SIGUSR1 signal...\n");
 
    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }
 
    return 0;
}

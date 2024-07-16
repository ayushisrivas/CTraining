#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
void sigint_handler(int signum) {
    printf("\nSIGINT received! Blocking SIGTERM temporarily...\n");
    sleep(10);
 
    printf("SIGINT handler finished. Unblocking SIGTERM.\n");
}
 
int main() {
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGTERM); 
    sa.sa_flags = 0;
 
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
 
    printf("SIGINT handler is set. Send SIGINT (Ctrl+C) to trigger.\n");
    while (1) {
        sleep(1);
    }
 
    return 0;
}

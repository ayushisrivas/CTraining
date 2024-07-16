#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
void sigalrm_handler(int signum) {
    if (signum == SIGALRM) {
        printf("SIGALRM received: Alarm went off!\n");
    }
}
 
int main() {
    signal(SIGALRM, sigalrm_handler);
    alarm(5);
    printf("Waiting for SIGALRM...\n");
    while (1) {
        sleep(1);
    }
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
int main() {
    pid_t receiver_pid;
 
    // Prompt user to enter PID of the receiver
    printf("Enter PID of the receiver process: ");
    if (scanf("%d", &receiver_pid) != 1) {
        fprintf(stderr, "Invalid input. Exiting...\n");
        return 1;
    }
 
    // Send SIGUSR1 signal to the specified process
    if (kill(receiver_pid, SIGUSR1) == -1) {
        perror("kill");
        return 1;
    }
 
    printf("Sent SIGUSR1 to process with PID %d\n", receiver_pid);
 
    return 0;
}

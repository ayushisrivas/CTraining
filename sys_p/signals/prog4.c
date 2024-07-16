#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
void sigint_handler(int signum) {
  printf("\nSIGINT received!\n");
}
 
int main() {
   signal(SIGINT, sigint_handler);
   sigset_t mask, prev_mask;
   sigemptyset(&mask);
   sigaddset(&mask, SIGINT);
   sigprocmask(SIG_BLOCK, &mask, &prev_mask);
   printf("SIGINT blocked for 10 seconds...\n");
   sleep(10);
   sigprocmask(SIG_SETMASK, &prev_mask, NULL);
   printf("SIGINT unblocked. You can now send SIGINT.\n");
   while (1) {
        sleep(1);
   }
    return 0;
}

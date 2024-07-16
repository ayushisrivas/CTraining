#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <errno.h>

#define QUEUE_NAME "/my_queue"
#define MAX_MSG_SIZE 1024

int main() {
    mqd_t mq;
    struct mq_attr attr;
    char buffer[MAX_MSG_SIZE + 1];
    unsigned int prio;

    // Set up attributes of the message queue
    attr.mq_flags = 0;          // Flags (unused)
    attr.mq_maxmsg = 10;        // Max number of messages in queue
    attr.mq_msgsize = MAX_MSG_SIZE; // Max size of each message

    // Open the message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    printf("Message queue opened successfully\n");

    // Receiving and processing messages based on priority
    while (1) {
        ssize_t nbytes = mq_receive(mq, buffer, MAX_MSG_SIZE, &prio);
        if (nbytes == -1) {
            perror("mq_receive");
            exit(1);
        }
        buffer[nbytes] = '\0'; // Null-terminate the received message
        printf("Received message with priority %u: %s\n", prio, buffer);

        // Simulate processing the message (sleep for 1 second)
        sleep(1);

        printf("Processed message with priority %u\n", prio);
    }

    // Close the message queue (never reached in this example)
    mq_close(mq);
    mq_unlink(QUEUE_NAME);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <errno.h>

#define QUEUE_NAME "/my_queue"
#define MAX_MSG_SIZE 1024

void *consumer(void *arg) {
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

    printf("Consumer started\n");

    // Receive and process messages from the queue
    while (1) {
        ssize_t nbytes = mq_receive(mq, buffer, MAX_MSG_SIZE, &prio);
        if (nbytes == -1) {
            perror("mq_receive");
            exit(1);
        }
        buffer[nbytes] = '\0'; // Null-terminate the received message
        printf("Consumer received: %s\n", buffer);
        usleep(500000); // Simulate processing time
    }

    // Close the message queue (never reached in this example)
    mq_close(mq);

    return NULL;
}

int main() {
    pthread_t consumers[2];  // Example: 2 consumer threads
    int num_consumers = sizeof(consumers) / sizeof(consumers[0]);

    // Create consumer threads
    for (int i = 0; i < num_consumers; ++i) {
        if (pthread_create(&consumers[i], NULL, consumer, NULL) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for all consumer threads to finish (never reached in this example)
    for (int i = 0; i < num_consumers; ++i) {
        if (pthread_join(consumers[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // This part is never reached because consumers run indefinitely
    printf("All consumers finished\n");

    return 0;
}


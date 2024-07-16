#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <errno.h>

#define QUEUE_NAME "/my_queue"
#define MAX_MSG_SIZE 1024
#define NUM_MESSAGES 10  // Number of messages each producer will send

void *producer(void *arg) {
    mqd_t mq;
    struct mq_attr attr;

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

    printf("Producer started\n");

    // Send messages to the queue
    for (int i = 0; i < NUM_MESSAGES; ++i) {
        char message[MAX_MSG_SIZE];
        sprintf(message, "Message %d from producer %ld", i + 1, (long)arg);
        if (mq_send(mq, message, strlen(message)+1, 1) == -1) {
            perror("mq_send");
            exit(1);
        }
        printf("Producer %ld sent: %s\n", (long)arg, message);
        usleep(100000); // Simulate delay between messages
    }

    // Close the message queue
    mq_close(mq);

    return NULL;
}

int main() {
    pthread_t producers[3];  // Example: 3 producer threads
    int num_producers = sizeof(producers) / sizeof(producers[0]);

    // Create producer threads
    for (long i = 0; i < num_producers; ++i) {
        if (pthread_create(&producers[i], NULL, producer, (void *)i) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for all producer threads to finish
    for (int i = 0; i < num_producers; ++i) {
        if (pthread_join(producers[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    printf("All producers finished\n");

    return 0;
}


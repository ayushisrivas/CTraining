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

    // Set up attributes of the message queue
    attr.mq_flags = 0;          // Flags (unused)
    attr.mq_maxmsg = 10;        // Max number of messages in queue
    attr.mq_msgsize = MAX_MSG_SIZE; // Max size of each message

    // Create the message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    printf("Message queue created or opened successfully\n");

    // Sending messages with different priorities
    struct {
        char message[MAX_MSG_SIZE];
        unsigned int priority;
    } messages[] = {
        { "Message with priority 1", 1 },
        { "Message with priority 3", 3 },
        { "Message with priority 2", 2 },
        { "Message with priority 1 again", 1 },
        { "Message with priority 2 again", 2 },
    };

    int num_messages = sizeof(messages) / sizeof(messages[0]);

    for (int i = 0; i < num_messages; ++i) {
        if (mq_send(mq, messages[i].message, strlen(messages[i].message)+1, messages[i].priority) == -1) {
            perror("mq_send");
            exit(1);
        }
        printf("Sent message with priority %u: %s\n", messages[i].priority, messages[i].message);
        sleep(1); // Simulate sending delay
    }

    // Close the message queue
    mq_close(mq);

    return 0;
}


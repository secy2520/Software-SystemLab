/*
--------------------------------------------------------
--------------------------------------------------------

Name - 27.c
Author - Jass Sadana
Description - Write a program to receive messages from the message queue.
with 0 as a flag
--------------------------------------------------------
--------------------------------------------------------
*/





#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

int main() {
    key_t key;
    int msgid, ret;

    key = ftok(".", 'a'); // Provide a valid path for key generation

    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    struct msg {
        long int mytype;
        char msg[800];
    } mq;

    msgid = msgget(key, IPC_CREAT | 0666); // Create or access the message queue

    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Enter a message type to receive: ");
    scanf("%ld", &mq.mytype);

    ret = msgrcv(msgid, &mq, sizeof(mq.msg), mq.mytype, 0);

    if (ret == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Message type: %ld\nMessage: %s\n", mq.mytype, mq.msg);

    return 0;
}

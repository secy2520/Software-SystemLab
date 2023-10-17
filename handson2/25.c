/*
--------------------------------------------------------
--------------------------------------------------------

Name - 25.c
Author - Jass Sadana
Description - Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
--------------------------------------------------------
--------------------------------------------------------
*/
















#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    key_t key;
    int msgid;

    key = ftok(".", 'a');
    msgid = msgget(key, 0666|IPC_CREAT);

    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    struct msqid_ds msg_info;

    if (msgctl(msgid, IPC_STAT, &msg_info) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message Queue Key: 0x%08X\n", key);
    printf("Owner UID: %d\n", msg_info.msg_perm.uid);
    printf("Owner GID: %d\n", msg_info.msg_perm.gid);
    printf("Creator UID: %d\n", msg_info.msg_perm.cuid);
    printf("Creator GID: %d\n", msg_info.msg_perm.cgid);
    printf("Access Permissions: %o\n", msg_info.msg_perm.mode);
    printf("Number of Messages: %lu\n", msg_info.msg_qnum);
    printf("Maximum Bytes: %lu\n", msg_info.msg_qbytes);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl (remove)");
    }

    return 0;
}


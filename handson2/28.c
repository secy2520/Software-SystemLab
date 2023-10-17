/*
--------------------------------------------------------
--------------------------------------------------------

Name - 28.c
Author - Jass Sadana
Description - Write a program to change the exiting message queue permission.
--------------------------------------------------------
--------------------------------------------------------
*/





#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msqid_ds queue_info;
int main() {
    key_t key;
    int msgid, ret;

    key = ftok(".", 'a'); 
    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }
    struct msg
    {
        long int mytype;
        char msg[800];
    } mq;
    msgid = msgget(key, IPC_CREAT | 0666); 
    if (msgid == -1)
      {
        perror("msgget");
        exit(1);
      }
  if (msgctl(msgid, IPC_STAT, &queue_info) == -1) 
     {
        perror("msgctl IPC_STAT");
        exit(1);
      }
   queue_info.msg_perm.mode = 0600;

    if (msgctl(msgid, IPC_SET, &queue_info) == -1) 
    {
        perror("msgctl IPC_SET");
        exit(1);
    }

    printf("Message queue permission changed successfully.\n");

    }

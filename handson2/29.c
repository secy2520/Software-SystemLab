/*
--------------------------------------------------------
--------------------------------------------------------

Name - 29.c
Author - Jass Sadana
Description - Write a program to remove the message queue.


--------------------------------------------------------
--------------------------------------------------------
*/














#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

int main()
{
key_t key;
int msgid;
key=ftok(".",'a');
msgid=msgget(key,IPC_CREAT|0666);
if (msgid == -1)
      {
        perror("msgget");
        exit(1);
      }
if(msgctl(msgid,IPC_RMID,0)==-1)
{
perror("msgctl IPC_RMID");
exit(1);
}
printf("Message queue removed successfully..\n");
return 0;
}

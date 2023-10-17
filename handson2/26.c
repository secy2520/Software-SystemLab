/*
--------------------------------------------------------
--------------------------------------------------------

Name - 26.c
Author - Jass Sadana
Description - Write a program to send messages to the message queue
--------------------------------------------------------
--------------------------------------------------------
*/









#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
int main()
{
key_t key;
int msgid,size;
key=ftok(".",'a');
struct msg
{
long int mytype;
char msg[800];
}mq;
msgid=msgget(key,IPC_CREAT|0666);
printf("Enter a message type to send\n");
scanf("%ld",&mq.mytype);
printf("Enter a message to send\n");
scanf(" %[^\n]",mq.msg);
size=strlen(mq.msg);
msgsnd(msgid, &mq, size+1,0);
return 0;
}

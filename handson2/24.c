/*
--------------------------------------------------------
--------------------------------------------------------

Name - 24.c
Author - Jass Sadana
Description - 24. Write a program to create a message queue and print the key and message queue id.
--------------------------------------------------------
--------------------------------------------------------
*/






#include<sys/msg.h>
#include<stdio.h>
int main()
{
int msgid;
key_t key;

key=ftok(".",'a');
msgid=msgget(key,IPC_CREAT | IPC_EXCL|0744);
printf("key=0x%0x\t msgid=%d\n", key,msgid);
return 0;
}

/*
-------------------------------------------------------
-------------------------------------------------------
Name - 29.c
Author - Jass Sadana
Description - Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date-1-8-23
-------------------------------------------------------
-------------------------------------------------------
*/

#include<stdio.h>
#include<sched.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
if(argc!=2)
{
printf("You are requested to enter the process name also.. \n");
}
pid_t pid1=atoi(argv[1]);
switch(sched_getscheduler(pid1))
{
case SCHED_FIFO:printf("Scheduling Policy is FIFO..\n");break;
case SCHED_RR:printf("Schedulung Policy is RR...\n");break;
case SCHED_OTHER :printf("Some other Scheduling Policy..\n");break;
default:printf("Unknow Policy...\n");break;
}
struct sched_param param;
param.sched_priority=99;
if(sched_setscheduler(pid1, SCHED_FIFO,&param)==-1)
{
printf("There is some error modifying the scheduling policy...\n");
exit(1);
}
printf("Scheduling Policy has been modified to FIFO..\n");
return 0;
}

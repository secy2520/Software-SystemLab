/*
-------------------------------------------------------
-------------------------------------------------------

Name-21.c
Author-Jass Sadana
Description-Write a program, call fork and print the parent and child process id.
Date-1-8-23
-------------------------------------------------------
-------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
int main(void)
{
if(!fork())
{
printf("Process ID of the child is.... %d\n", getpid());
}
else
{
int status;
wait(&status);
printf("Process ID of the parent is.... %d \n", getppid());
}
return 0;
}



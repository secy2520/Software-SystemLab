/*
-------------------------------------------------------
-------------------------------------------------------
Name - 27c.c
Author - Jass Sadana
Description - Write a program to execute ls -Rl by the following system calls
c. execlp
Date-1-8-23
-------------------------------------------------------
-------------------------------------------------------
*/


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
if(execlp("/bin/ls", "ls", "-R","-l", NULL)==-1)
{
printf("There is some error...\n");
}
return 0;
}



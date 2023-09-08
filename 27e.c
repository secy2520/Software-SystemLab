/*
-------------------------------------------------------
-------------------------------------------------------
Name - 27e.c
Author - Jass Sadana
Description - Write a program to execute ls -Rl by the following system calls
e. execvp
Date-1-8-23
-------------------------------------------------------
-------------------------------------------------------
*/



#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
char *args[]={"ls", "-R", "-l", NULL};
if(execvp("ls", args)==-1)
{
printf("There is some error...\n");
}
return 0;
}


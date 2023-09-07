/*
-------------------------------------------------------
-------------------------------------------------------

Name-1c.c
Author-Jass Sadana
Description-FIFO (mkfifo Library Function or mknod system call)

-------------------------------------------------------
-------------------------------------------------------
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
const char *filename="mkfifo";

if(mkfifo(filename, 0666)== -1)
{
perror("Error creating FIFO");
return 1;
}
printf("File created successfully");
return 0;
}

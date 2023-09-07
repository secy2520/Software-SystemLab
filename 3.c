/*
-------------------------------------------------------
-------------------------------------------------------

Name-3.c
Author-Jass Sadana
Description-Write a program to create a file and print the file descriptor value. Use creat ( ) system call

-------------------------------------------------------
-------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
const char *filename="using_creat";
int file_d=creat(filename,0666);
if(file_d==-1)
{
perror("Error creating file");
}
else
printf("File descriptor created with value = %d", file_d);

return 0;
}

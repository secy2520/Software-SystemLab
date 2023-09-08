/*
-------------------------------------------------------
-------------------------------------------------------

Name-4.c
Author-Jass Sadana
Description-Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date-11-8-23
-------------------------------------------------------
-------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
const char *filename="sample.txt";
const char *data="Now Im writing through CLI";
int fd=open(filename,O_RDWR | O_EXCL, 0666);
write(fd,data,strlen(data));
if(fd==-1)
perror("There is some error");
close(fd);
return 0;
}

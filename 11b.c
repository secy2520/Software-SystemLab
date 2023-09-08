/*
-------------------------------------------------------
-------------------------------------------------------

Name-11b.c
Author-Jass Sadana
Description-Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
b) use dup2
Date-18-8-23
-------------------------------------------------------
-------------------------------------------------------
*/


#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
int fd1,fd2,fd3;
fd1=open("crust",O_CREAT | O_EXCL, 777 );
if(fd1==-1)
{
printf("Sorry there is some error");
}
printf("originally assigned FD is %d", fd1);
fd2=dup2(fd1,7);
//dup(fd1,fd2);
if(fd2==-1)
{
printf("Sorry to create a dup fd");
exit(1);
}
printf("Newly assigned fd is %d", fd2);
return 0;
}

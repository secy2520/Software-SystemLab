/*
--------------------------------------------------------
--------------------------------------------------------

Name - 22.c
Author - Jass Sadana
Description - Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO 

--------------------------------------------------------
--------------------------------------------------------
*/










#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
fd_set tfds;
struct timeval tv;
int fd,retval;
char buff[80];
FD_ZERO(&tfds);
fd=open("testingfifo", O_RDONLY);
FD_SET(fd,&tfds);
tv.tv_sec=10;
retval=select(10,&tfds,NULL,NULL,&tv);
if(retval)
{
printf("Ready to write data...\n");
}
else
{
printf("No data within 10 secs...\n");
exit(0);
}
read(fd,buff,sizeof(buff));
printf("The data written into FIFO is... %s", buff);
return 0;
}

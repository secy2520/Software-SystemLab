/*
-------------------------------------------------------
-------------------------------------------------------

Name-13.c
Author-Jass Sadana
Description-Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date-25-8-23
-------------------------------------------------------
-------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/select.h>
int main()
{
fd_set fdsread;
struct timeval ts;

FD_ZERO(&fdsread);
FD_SET(0,&fdsread);

ts.tv_sec=10;
ts.tv_usec=0;
int rtval;

rtval =  select(1,&fdsread,NULL,NULL,&ts);
if(rtval==-1)
{
printf("There is some error");
}
else if(rtval)
{
printf("Data is available now");
}
else
printf("No data within 10 seconds");
return 0;
}

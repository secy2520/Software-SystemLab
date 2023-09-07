/*
-------------------------------------------------------
-------------------------------------------------------

Name-6.c
Author-Jass Sadana
Description-Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

-------------------------------------------------------
-------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
int fd_open;
char buff[200];
int reader=read(0,buff,sizeof(buff));
if(reader > 1)
{
write(1,buff,reader);
}
return  0;
}

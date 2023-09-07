/*
-------------------------------------------------------
-------------------------------------------------------

Name-12.c
Author-Jass Sadana
Description-Write a program to find out the opening mode of a file. Use fcntl.

-------------------------------------------------------
-------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd1;
fd1=open("destfile", O_RDONLY);
if(fd1 == -1)
{
printf("Error opening file");
}
int flag=fcntl(fd1, F_GETFL);  //F_GETFL is used to retrieve  assosicated flags with the file
if(flag==-1)
{
printf("Bakwaas");
}
int acc_mode=flag & O_ACCMODE; //O_ACCMODE is there in fcntl.h
if(acc_mode== O_RDONLY)
{
printf("The file is opened in Read Mode Only");
}
if(acc_mode== O_WRONLY)
{
printf("The file is opened in Read Mode Only");
}
if(acc_mode== O_RDWR)
{
printf("The file is opened in Read Mode Only");
}
close(fd1);
return 0;
}

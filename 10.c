/*
-------------------------------------------------------
-------------------------------------------------------

Name-10.c
Author-Jass Sadana
Description-Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.

-------------------------------------------------------
-------------------------------------------------------
*/


#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
int fd_write;
char buff[10];
 fd_write=open("trust",O_RDONLY | O_WRONLY);
if(fd_write ==-1)
{
printf("Koi faayda nhi h, do whatever you want");
}
printf("Daaliye file mei janaab jo daalna hai\n");
scanf("%s",buff);
int err_write=write(fd_write, buff, sizeof(buff));
if(err_write==-1)
{
printf("Kuch toh gadbad hai janaab\n");
}
char buff1[10];
int offset=lseek(fd_write,20,SEEK_SET);
printf("Abhi hmaara pointer iss position par hai %d", offset);
printf("Daaliye file mei janaab jo ab 10 bytes k baad daalna hai");
scanf("%s",buff1);
int err1_write=write(fd_write, buff1, sizeof(buff1));
if(err1_write==-1)
{
printf("Gadbad hai rehene dijiye");
}
close(fd_write); 
return 0;
}

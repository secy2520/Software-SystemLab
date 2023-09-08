
/*
-------------------------------------------------------
-------------------------------------------------------

Name - 1b.c
Author - Jass Sadana
Description - Hard linkfile program (link system call)
Date-11-8-23
-------------------------------------------------------
-------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
const char *filename="hardlinkexample.txt";
const char *hardlink="hardlink";

if(link(filename,hardlink)==0)
{
printf("File created successfully\n");
return 1;
}
else
{
perror("There is some error\n");
}
return 0;
}

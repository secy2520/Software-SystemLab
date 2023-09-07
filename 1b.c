/*
-------------------------------------------------------
-------------------------------------------------------

Name - 1a.c
Author - Jass Sadana
Description - Hard linkfile program (symlink system call)

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

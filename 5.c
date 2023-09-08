/*
-------------------------------------------------------
-------------------------------------------------------

Name-5.c
Author-Jass Sadana
Description-Write a program to create five new files with infinite loop.
Date-11-8-23
-------------------------------------------------------
-------------------------------------------------------
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
FILE *files[5];
for(int i=0;i<5;i++)
{
char filename[20];
sprintf(filename,"file%d",i);
files[i]=fopen(filename,"w");
if(files[i]==NULL)
{
perror("Failed to open file");

exit(1);
}
}
while(1)
{
sleep(1);
}
for(int i=0;i<5;i++)
{
fclose(files[i]);
}
return 0;
}

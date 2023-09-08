/*
-------------------------------------------------------
-------------------------------------------------------
Name-17a.c
Author-Jass Sadana
Description- Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file
Date-25-8-23
-------------------------------------------------------
-------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

struct 
{
     int train_num;
     int ticket_count;
} db[3];

int main()
{
int fd;
for(int i=0;i<3;i++)
{
db[i].train_num=i+1;
db[i].ticket_count=0;
}
fd=open("record.txt", O_RDWR | O_CREAT );
write(fd,db,sizeof(db));
close(fd);

return 0;
}


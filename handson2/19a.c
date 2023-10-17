/*
--------------------------------------------------------
--------------------------------------------------------

Name - 19.c
Author - Jass Sadana
Description - Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function

--------------------------------------------------------
--------------------------------------------------------
*/


















#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
int choice;
printf("Enter 1 to make fifo file using mkfifo ....\n Enter 2 for using mknod library function\n");
scanf("%d",&choice);
if(choice==1)
{
if (mkfifo("myfifo", 0666) == -1) 
{
        perror("Error creating FIFO");
        exit(1);
}
else 
printf("Successful using mkfifo..\n");
}
else if(choice==2)
{
 if (mknod("myfifo", S_IFIFO | 0666, 0) == -1) {
        perror("Error creating FIFO");
        exit(1);
    } else {
        printf("FIFO (named pipe) 'myfifo' created successfully using mknod...\n");
    }

}
return 0;
}

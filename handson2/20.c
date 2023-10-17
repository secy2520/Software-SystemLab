
/*
--------------------------------------------------------
--------------------------------------------------------

Name - 20.c
Author - Jass Sadana
Description - Write two programs so that both can communicate by FIFO -Use one way communication.

--------------------------------------------------------
--------------------------------------------------------
*/







#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
int fd;
char buff[80];
fd=open("testingfifo", O_WRONLY);
while(1)
{
printf("Enter the message to the fifo\n");
scanf(" %s",buff);
write(fd,buff,sizeof(buff));
}
return 0;
}

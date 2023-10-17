 
/*
--------------------------------------------------------
--------------------------------------------------------

Name - 20.c
Author - Jass Sadana
Description - 20. Write two programs so that both can communicate by FIFO -Use one way communication.

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
fd=open("testingfifo", O_RDONLY);
while(1)
{
read(fd,buff,sizeof(buff));
printf("Reading the message from the fifo\n %s", buff);

}
return 0;
}


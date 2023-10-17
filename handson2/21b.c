/*
--------------------------------------------------------
--------------------------------------------------------

Name - 21.c
Author - Jass Sadana
Description - Write two programs so that both can communicate by FIFO -Use two way communications. 

--------------------------------------------------------
--------------------------------------------------------
*/












#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int fdw, fdr;
char buff_r[80], buff_w[80];
mkfifo("myfirst",0744);
mkfifo("myfisto",0744);
fdr=open("myfirst", O_RDONLY | O_WRONLY);
fdw=open("myfisto", O_WRONLY | O_WRONLY);
if(fdr==-1 || fdw==-1)
{
printf("There is some error..\n");
}
while(1)
{
printf("Enter the message..\n");
scanf("%[^\n]", buff_w);
write(fdw,buff_w,sizeof(buff_w));
read(fdr,buff_r,sizeof(buff_r));
printf("Message from the FIFO is... %s", buff_r);
}
return 0;
}

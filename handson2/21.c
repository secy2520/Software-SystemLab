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
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int fdw, fdr;
char buff_r[80], buff_w[80];
fdr=open("myfisto", O_RDONLY,);
fdw=open("myfirst", O_WRONLY);
while(1)
{
read(fdr,buff_r,sizeof(buff_r));
printf("Message from pipe is..%s\n",buff_r);
printf("Enter the message: \n");
scanf("%[^\n]", buff_w);
write(fdw,buff_w,sizeof(buff_w));
}
return 0;
}

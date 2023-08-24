#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
int fd1,fd2,fd3;
fd1=open("tryst",O_CREAT | O_EXCL, 777 );
if(fd1==-1)
{
printf("Sorry there is some error");
}
printf("originally assigned FD is %d", fd1);
fd2=dup(fd1);
//dup(fd1,fd2);
if(fd2==-1)
{
printf("Sorry to create a dup fd");
exit(1);
}
printf("Newly assigned fd is %d", fd2);
return 0;
}

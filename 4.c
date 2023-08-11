#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
const char *filename="sample.txt";
const char *data="Now Im writing through CLI";
int fd=open(filename,O_WRONLY | O_EXCL, 0666);
write(fd,data,strlen(data));
if(fd==-1)
perror("There is some erro");
close(fd);
return 0;
}

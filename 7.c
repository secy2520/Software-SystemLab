#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[] )
{
if(argc != 3)
{
printf("Please enter a new file name");
return 0;
}
int fd_read;
int fd_write;
//char buff;
fd_read=open(argv[1], O_RDONLY);
fd_write=open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 777);
if(fd_read==-1 || fd_write==-1)
{
printf("Useless");
}
while(1)
{
char buff;
int char_read=read(fd_read,&buff,1);
if(char_read==0)
break;
int char_write=write(fd_write,&buff,1);
}

int fd_read_close=close(fd_read);
int fd_write_close=close(fd_write);
if(fd_read_close==-1 || fd_write_close==-1)
{
printf("Useless");
}

return 0;
}

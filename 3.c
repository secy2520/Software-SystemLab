#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
const char *filename="using_creat";
int file_d=creat(filename,0666);
if(file_d==-1)
{
perror("Error creating file");
}
else
printf("File descriptor created with value = %d", file_d);

return 0;
}

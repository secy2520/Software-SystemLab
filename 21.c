#include<stdio.h>
#include<unistd.h>
int main(void)
{
if(!fork())
{
printf("Process ID of the child is.... %d\n", getpid());
}
else
{
printf("Process ID of the parent is.... %d \n", getppid());
}
return 0;
}



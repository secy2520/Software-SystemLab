#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void)
{
if(!fork())
{
printf("Child process id is... %d\n", getpid());
printf("Now parent is gonna zombie\n");
}
else
{
printf("Im the parent... %d\n", getpid());
//sleep(2);
int status;
wait(&status);
printf("Hello this side is parent and Im still alive \n");
printf("Gonna Die...Byeee\n");
}
return 0;
}

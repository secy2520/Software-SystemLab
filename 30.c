#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(void)
{
pid_t child;
child=fork();
if(!child)
{
setsid();
chdir("/");
umask(0);
while(1)
{
sleep(2);
printf("Process ID is %d \n", getpid());
printf("Daemon process is running\n");
}
}
else 
{
exit(0);
}
return 0;
}

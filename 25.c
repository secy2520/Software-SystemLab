#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
if (!fork())
{
if (!fork())
{
printf("Hello, this is child 3 (PID %d) and my parent is PID %d\n", getpid(), getppid());
}
else
{
int status;
wait(&status);
printf("Hello, this is child 2 (PID %d) and my parent is PID %d\n", getpid(), getppid());
}
}
else
{
if(!fork())
{
printf("Hello, this is child 1 (PID %d) and my parent is PID %d\n", getpid(), getppid());
}
else
{
printf("Hello, this is the parent (PID %d)\n", getpid());

for (int i = 0; i < 3; i++)
       {
          int status;
             wait(&status);
       }
       }
    }

    return 0;
}

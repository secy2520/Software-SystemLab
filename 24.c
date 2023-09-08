

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
if(!fork())
{
printf("I am child and my ID is.. %d\n", getpid());
sleep(3);
printf("Hey this child and I am orphan now...Press enter to kill me... \n");
getchar();
}
else
{
printf("Parent process and my ID is... %d\n", getpid());
sleep(1);
printf("Now parent is exiting...\n");
exit(1);
}
return 0;
}

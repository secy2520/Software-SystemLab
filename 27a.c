#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
if(
execl("/bin/ls", "ls", "-R","-l", NULL)==-1)
{
printf("There is some error...\n");
}
return 0;
}

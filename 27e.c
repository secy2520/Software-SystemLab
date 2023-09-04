#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
char *args[]={"ls", "-R", "-l", NULL};
if(execvp("ls", args)==-1)
{
printf("There is some error...\n");
}
return 0;
}


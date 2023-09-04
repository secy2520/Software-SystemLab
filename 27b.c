#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

extern char **environ;
int main(void)
{

char *my_envp[] = {
"MY_VARIABLE=Hello",
"ANOTHER_VARIABLE=World",
        NULL
};
if(execle("/bin/ls", "ls", "-R","-l", NULL, my_envp)==-1)
{
printf("There is some error...\n");
}
return 0;
}





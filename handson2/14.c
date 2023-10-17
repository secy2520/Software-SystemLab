#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)\
{
int fd[2], gt;
pipe(fd);
char star[20];
char start[20];
scanf("%s", star);
write(fd[1],star,sizeof(star));
read(fd[0],start,sizeof(start));
printf("I have read this from the user... %s", start);
close(fd[0]);
close(fd[1]);
return 0;
}

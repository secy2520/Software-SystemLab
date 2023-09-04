#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main (void)
{
printf("Hello World....\n");
int x;
x=nice(0);
printf("Current priority of the process is %d..", x);

int y;
y=nice(5);
printf("Current priority of the process is %d..", y);


return 0;
}

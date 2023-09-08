/*
-------------------------------------------------------
-------------------------------------------------------

Name-20.c
Author-Jass Sadana
Description-Find out the priority of your running program. Modify the priority with nice command
Date-1-8-23
-------------------------------------------------------
-------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

int main(void)
{
    printf("Hello World....\n");
    int x;

    x = nice(0);
    if (x == -1)
    {
        perror("Error setting priority: ");
    }
    else
    {
        printf("Current priority of the process is %d..\n", x);
    }

    int y;
    y = nice(5);
    if (y == -1)
    {
        perror("Error setting priority: ");
    }
    else
    {
        printf("Current priority of the process is %d..\n", y);
    }

    return 0;
}


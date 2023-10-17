/*
--------------------------------------------------------
--------------------------------------------------------

Name-17c.c
Author-Jass Sadana
Description-Write a program to execute ls -l | wc.
c. use fcntl

--------------------------------------------------------
--------------------------------------------------------
*/


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
    int fd[2]; 
    pipe(fd);

    if (!fork()) 
       {
        close(fd[0]);
        fcntl(fd[1],F_SETFD, FD_CLOEXEC);
        execl("/bin/ls", "ls", "-l", (char *)0);
       exit(0);
        } 
   else
      {

        close(fd[1]);
        execl("/usr/bin/wc", "wc", (char *)0);
        exit(0);
    }

    return 0;
}

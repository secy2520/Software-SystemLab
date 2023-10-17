/*
--------------------------------------------------------
--------------------------------------------------------

Name - 18.c
Author - Jass Sadana
Description - Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2

--------------------------------------------------------
--------------------------------------------------------
*/











#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (!fork()) {
        dup2(fd1[1],1);
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execl("/bin/ls", "ls", "-l", (char *)0);
       exit(0);
    } else {
       if(!fork())
         {
       dup2(fd1[1],1);
        dup2(fd2[0],0);
        close(fd2[0]);
        close(fd2[1]);
        close(fd1[0]);
        close(fd1[1]);
        execl("/usr/bin/grep", "grep","^d",(char *)0);
        exit(0);
         }
         else
         {
        dup2(fd2[0],0);
        close(fd2[0]);
        close(fd2[1]);
        close(fd1[0]);
        close(fd1[1]);
        execl("/usr/bin/wc", "wc", (char *)0);
        exit(0);

         }
    }

    return 0;
}

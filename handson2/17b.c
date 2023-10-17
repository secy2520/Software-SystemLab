/*
--------------------------------------------------------
--------------------------------------------------------

Name-17b.c
Author-Jass Sadana
Description-Write a program to execute ls -l | wc.
b. use dup2

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
    int fd[2]; // Only one pipe is needed
    pipe(fd);

    if (!fork()) {
        // Child process (ls)
        close(1);
        dup2(fd[1],1);
        close(fd[0]);
        close(fd[1]);
        execl("/bin/ls", "ls", "-l", (char *)0);
       exit(0);
    } else {
        // Parent process
        close(0);
        dup2(fd[0],0);
        close(fd[0]);
        close(fd[1]);
        execl("/usr/bin/wc", "wc", (char *)0);
        exit(0);
    }

    return 0;
}

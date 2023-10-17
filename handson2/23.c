/*
--------------------------------------------------------
--------------------------------------------------------

Name - 23.c
Author - Jass Sadana
Description - Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer). 

--------------------------------------------------------
--------------------------------------------------------
*/







#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    printf("Max. no. of files that can be opened: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Size of a pipe (circular buffer): %ld bytes\n", fpathconf(fd[0], _PC_PIPE_BUF));

    return 0;
}

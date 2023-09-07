/*
-------------------------------------------------------
-------------------------------------------------------

Name-11c.c
Author-Jass Sadana
Description-Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
a. use fcntl

-------------------------------------------------------
-------------------------------------------------------
*/


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
    int fd_op;
    fd_op = open("trust", O_RDONLY);
    
    if (fd_op == -1) {
        printf("Sorry there were some issues\n");
    } else {
        printf("Old file descriptor is %d\n", fd_op);
    }

    int new_fd = fcntl(fd_op, F_DUPFD);
    if (new_fd == -1) {
        printf("Sorry new fd cant be created\n");
    } else {
        printf("New file descriptor is %d\n", new_fd);
    }

    return 0;
}

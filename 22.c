/*
-------------------------------------------------------
-------------------------------------------------------

Name - 22.c
Author - Jass Sadana
Description - Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes.

-------------------------------------------------------
-------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    int fd1;
    fd1 = open("testingrecord.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    
    if (fd1 == -1) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Child process
        char buff[200];
        printf("Enter the content to be written by child...\n");
        scanf("%s", buff); // Limit input to 199 characters to avoid buffer overflow
        write(fd1, buff, strlen(buff));
       write(fd1,"\n",1);
    } else { // Parent process
        char buff1[200];
        printf("Enter the content to be written by parent...\n");
        scanf("%s", buff1); // Limit input to 199 characters to avoid buffer overflow
        write(fd1, buff1, strlen(buff1));
        write(fd1, "\n",1);
        int status;
        wait(&status);
        
    }

    close(fd1);
    return 0;
}

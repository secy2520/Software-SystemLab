#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t childpid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    childpid = fork();

    if (childpid == -1) {
        perror("fork");
        exit(1);
    }

    char buff[200];

    if (childpid == 0) {
        close(fd[1]);
        read(fd[0], buff, sizeof(buff));
        printf("The Received string is: %s\n", buff);
    } else {
        close(fd[0]);
        write(fd[1], "Hello paji, kida fir? vadiya.....\n",34);
        close(fd[1]); 
        int status;
        wait(&status);
    }

    return 0;
}

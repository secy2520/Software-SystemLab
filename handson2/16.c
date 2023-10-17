#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd1[2], fd2[2];
    pid_t childpid;
pipe(fd1);
pipe(fd2);
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
    char buff1[200];

    if (childpid == 0) {
        close(fd1[1]);
        close(fd2[0]);
        write(fd2[1],"Child this side, assi vi vadiya ha...\n",38);
        close(fd2[1]);
        read(fd1[0], buff, sizeof(buff));
        printf("The Received string from parent is: %s\n", buff);
    } else {
       close(fd1[0]);
       write(fd1[1], "Hello paji, kidda fir? vadiya.....\n",34);
       read(fd2[0],buff1,sizeof(buff1));
       printf("Received string from child is .... %s \n", buff1);
        close(fd1[1]); 
        int status;
        wait(&status);
    }

return 0;
}

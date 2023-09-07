/*
-------------------------------------------------------
-------------------------------------------------------

Name-18a.c
Author-Jass Sadana
Description- Write a program to perform Record locking.
a. Implement write lock
-------------------------------------------------------
-------------------------------------------------------
*/



#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

struct {
    int enrollment;
    char name[200];
    int dept;
} db;

int main() {
    int fd;
    struct flock lock, savelock;
    int input;

    fd = open("record1.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    printf("Enter the record number which you want to write in the range 1-8:\n");
    scanf("%d", &input);

    lock.l_type = F_WRLCK;
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();
    savelock = lock;

    // Check the existing locks
    if (fcntl(fd, F_GETLK, &lock) == -1) {
        perror("Error checking locks");
        close(fd);
        exit(1);
    } else if (lock.l_type == F_RDLCK) {
        printf("Process has a read lock already on this record! Waiting...\n");
}
        while (lock.l_type == F_RDLCK)
 {
            fcntl(fd, F_GETLK, &lock);
        }
 

    // Set the write lock
    if (fcntl(fd, F_SETLKW, &savelock) == -1) {
        perror("Error setting write lock");
        close(fd);
        exit(1);
    }

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    printf("Enter the data at this point:\n");
    scanf("%d", &db.enrollment);
    scanf("%s", db.name);
    scanf("%d", &db.dept);
    write(fd, &db, sizeof(db));

    savelock.l_type = F_UNLCK;

    // Release the lock
    if (fcntl(fd, F_SETLK, &savelock) == -1) {
        perror("Error unlocking");
        close(fd);
        exit(1);
    }

    close(fd);
    printf("Record written successfully\n");

    return 0;
}

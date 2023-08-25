#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

struct {
    int train_num;
    int train_count;
} db;

int main() {
    int fd, input;
    fd = open("record.txt", O_RDWR);
    
    printf("Enter the train number 1, 2, or 3: ");
    scanf("%d", &input);

    struct flock lock, savelock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();
    savelock = lock;

    fcntl(fd, F_GETLK, &lock);

    if (lock.l_type == F_WRLCK) {
        printf("Someone is already updating. Waiting for lock...\n");
        while (lock.l_type == F_WRLCK) {
            fcntl(fd, F_GETLK, &lock);
        }
    }

    // Place a write lock
    if (fcntl(fd, F_SETLK, &savelock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));
    printf("Before entering the critical section\n");

    printf("Ticket number is %d\n", db.train_count);
    db.train_count++;
    lseek(fd, -sizeof(db), SEEK_CUR);
    write(fd, &db, sizeof(db));
    printf("Confirm your ticket by pressing enter\n");
    getchar();
    getchar();

    // Release the lock
    savelock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &savelock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    close(fd);
    printf("Booked\n");

    return 0;
}


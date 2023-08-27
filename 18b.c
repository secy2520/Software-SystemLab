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

    printf("Enter the record number which you want to read in the range 1-8:\n");
    scanf("%d", &input);

    lock.l_type = F_RDLCK;
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
    }

    if (lock.l_type == F_WRLCK) {
        printf("Process has a write lock already on this particular record! Waiting...\n");
        while (lock.l_type == F_WRLCK) {
            fcntl(fd,F_GETLK, &lock);
        }
       
    }

    printf("Before entering into the critical section\n");

    // Set the read lock
    if (fcntl(fd, F_SETLKW, &savelock) == -1) {
        perror("Error setting read lock");
        close(fd);
        exit(1);
    }

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));
    printf("Press enter to come out of the critical section\n");
    getchar();
    getchar();

    savelock.l_type = F_UNLCK;

    // Release the lock
    if (fcntl(fd, F_SETLK, &savelock) == -1) {
        perror("Error unlocking");
        close(fd);
        exit(1);
    }

    printf("Successfully unlocked\n");

    close(fd);

    return 0;
}



/*
-------------------------------------------------------
-------------------------------------------------------

Name-14.c
Author-Jass Sadana
Description-Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date-25-8-23
-------------------------------------------------------
-------------------------------------------------------
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Define constants for file types
#define REGULAR_FILE 1
#define DIRECTORY 2
#define SYMBOLIC_LINK 3
#define CHARACTER_DEVICE 4
#define BLOCK_DEVICE 5
#define FIFO 6
#define SOCKET 7
#define UNKNOWN 8

int get_file_type(const char *file_path) {
    struct stat file_stat;

    if (stat(file_path, &file_stat) == -1) {
        perror("stat");
        return -1;
    }

    if (S_ISREG(file_stat.st_mode)) {
        return REGULAR_FILE;
    } else if (S_ISDIR(file_stat.st_mode)) {
        return DIRECTORY;
    } else if (S_ISLNK(file_stat.st_mode)) {
        return SYMBOLIC_LINK;
    } else if (S_ISCHR(file_stat.st_mode)) {
        return CHARACTER_DEVICE;
    } else if (S_ISBLK(file_stat.st_mode)) {
        return BLOCK_DEVICE;
    } else if (S_ISFIFO(file_stat.st_mode)) {
        return FIFO;
    } else if (S_ISSOCK(file_stat.st_mode)) {
        return SOCKET;
    } else {
        return UNKNOWN;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    int file_type = get_file_type(file_path);

    switch (file_type) {
        case REGULAR_FILE:
            printf("The file type is: Regular File\n");
            break;
        case DIRECTORY:
            printf("The file type is: Directory\n");
            break;
        case SYMBOLIC_LINK:
            printf("The file type is: Symbolic Link\n");
            break;
        case CHARACTER_DEVICE:
            printf("The file type is: Character Device\n");
            break;
        case BLOCK_DEVICE:
            printf("The file type is: Block Device\n");
            break;
        case FIFO:
            printf("The file type is: FIFO (Named Pipe)\n");
            break;
        case SOCKET:
            printf("The file type is: Socket\n");
            break;
        default:
            printf("Unknown file type\n");
            break;
    }

    return 0;
}



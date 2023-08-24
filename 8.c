#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char buff[20];
    int fd_read = open("trust", O_RDONLY);
    
    if (fd_read == -1) {
        printf("File does not exist!\n");
        return 1;  // Return an error code to indicate failure
    }
    
    int bytesRead;
    while ((bytesRead = read(fd_read, buff, sizeof(buff))) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            char ch = buff[i];
            
            if (ch == '\n') {
                printf(",");
                printf("\n");
            } else {
                printf("%c",ch);
            }
        }
    }
    
    close(fd_read);
    return 0;
}

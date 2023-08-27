#include <sys/types.h>   
#include <unistd.h>      
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
  int fd;
  struct flock lock, savelock;

  fd = open("record1.txt", O_RDWR);
  lock.l_type    = F_WRLCK;  
  lock.l_start   = 0;
  lock.l_whence  = SEEK_SET;
  lock.l_len     = 0;        
  savelock = lock;
  fcntl(fd, F_GETLK, &lock);  
   if (lock.l_type == F_RDLCK)
  {
     printf("Process  has a read lock already!.... Waiting\n");
     while(lock.l_type==F_RDLCK)
    {
     fcntl(fd,F_GETLK, &lock); 
}
}
if(fcntl(fd, F_SETLKW, &savelock)==-1)
{
    printf("Error implementing write lock..\n");
}
printf("Now implementing the write lock..\n");
printf("Press enter to free the lock and come out of critical section...\n");

//getchar();
getchar();
savelock.l_type=F_UNLCK;
    if (fcntl(fd, F_SETLK, &savelock) == -1) {
        perror("Error unlocking");
        close(fd);
        exit(1);
    }

    printf("Successfully unlocked and come out of the critical section\n");

    close(fd);

    return 0;
}

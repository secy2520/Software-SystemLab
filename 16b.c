#include <stdio.h>      
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h> 
int main()
{
  struct flock lock, savelock;
  int fd;

  fd = open("record1.txt", O_RDONLY);
  lock.l_type = F_RDLCK;
  lock.l_start = 0;
  lock.l_whence = SEEK_SET;
  lock.l_len = 0;
  savelock = lock;
  fcntl(fd, F_GETLK, &lock);
  if (lock.l_type == F_WRLCK)
  {
      printf("File is write-locked by process....Waiting!!\n");
      while(lock.l_type==F_WRLCK)
  {
    fcntl(fd, F_GETLK, &lock);
  }
  }
if(  fcntl(fd,F_SETLKW, &savelock)==-1)
{
printf("Error getting the read lock...");
}
  printf("Now getting the read lock....\n");
 printf("Press enter to come out of the critical section...\n");
//getchar();
getchar();
savelock.l_type=F_UNLCK;
  fcntl(fd, F_SETLK, &savelock);
  printf("You are successfully out of the critical section and unlocked.\n");
  close(fd);
return 0;
}

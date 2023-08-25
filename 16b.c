#include <stdio.h>      
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
  struct flock lock, trylock;
  int fd;

  fd = open("record1.txt", O_RDONLY);
  lock.l_type = F_RDLCK;
  lock.l_start = 0;
  lock.l_whence = SEEK_SET;
  lock.l_len = 50;
  trylock = lock;
  fcntl(fd, F_GETLK, &lock);
  if (lock.l_type == F_WRLCK)
  {
      printf("File is write-locked by process.\n");
      exit(1);
  }
  fcntl(fd, F_SETLK, &trylock);
  pause();
}

/*
--------------------------------------------------------
--------------------------------------------------------

Name - 30.c
Author - Jass Sadana
Description - Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory


--------------------------------------------------------
--------------------------------------------------------
*/






#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int key,shmid,choice;
char *ptr;
key=ftok(".",'a');
shmid=shmget(key,1024,IPC_CREAT|0744);
ptr=shmat(shmid, (void *)0, 0);

printf("Here are the choices for the shared memory program..\n");
printf("Enter your choice:\n 1.writing data to the shared memory\n 2.using O_RDONLY flag and check if we are able to write or not\n 3.Detach from the shared memory\n 4.Remove shared memory\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter the data to be written in shared memory..\n");
       scanf(" %[^\n]", ptr);
       break;
case 2:ptr=shmat(shmid, (void *)0, SHM_RDONLY);
      printf("Enter the data to be written in shared memory..\n");
       scanf(" %[^\n]", ptr);
       break;
case 3:shmdt(ptr);
       printf("Shared memory detached successfully.\n");
       break;
case 4:if (shmctl(shmid, IPC_RMID, NULL) == -1) 
        {
        perror("shmctl IPC_RMID");
        exit(1);
         }
       printf("Shared memory removed successfully.\n");
       break
}
return 0;
}

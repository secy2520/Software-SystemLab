#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
const char *filename="./symlinkfile";
const char  *sympath="symlink.txt";
if(symlink(filename, sympath)==0)
{
printf("Symbolic link created successfully\n");
return 1;
}
else
{
printf("Error creating symbolic linkfile\n");
}
return 0;
}

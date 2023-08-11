#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
FILE *files[5];
for(int i=0;i<5;i++)
{
char filename[20];
sprintf(filename,"file%d",i);
files[i]=fopen(filename,"w");
if(files[i]==NULL)
{
perror("Failed to open file");

exit(1);
}
while(1)
{
fprintf(files[i],"This is the file");
//sleep(1);
}
}
for(int i=0;i<5;i++)
{
fclose(files[i]);
}
return 0;
}

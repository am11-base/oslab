#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
  for(int i=1;i<=2;i++){
  if(fork() == 0)
     printf("\nChild with pid %d and parent pid %d at level \n", getpid(), getppid());
    else if(fork() == 0)
     printf("\nChild with pid %d and parent pid %d at level \n", getpid(), getppid());
   else
     {
     wait(NULL);
     exit(0);

   }}
}

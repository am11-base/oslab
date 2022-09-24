#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <stdlib.h>


void main()
{
 int n;
 printf("Enter the value of N: ");
 scanf("%d", &n);
 printf("\nParent  with pid %d at level 0\n", getpid());
 for(int i = 1; i <= n; i++)
{  if(fork() == 0)
   printf("Child with pid %d and parent pid %d at level %d\n", getpid(), getppid(), i);
  else if(fork() == 0)
   printf("Child with pid %d and parent pid %d at level %d\n", getpid(), getppid(), i);
  else
   {
   wait(NULL);
   exit(0);

  }
 }
}

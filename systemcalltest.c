#include<stdio.h>
#include<unistd.h>
void main()
{
  fork();
  printf("%d %d\n",getpid(),getppid() );
}

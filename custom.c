#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
void main()
{
  printf("\n A:Parent process (pid : %d)\n",getpid() );
  int b=fork();
  if(b==0)
  {
    printf("\n B:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );

    int d=fork();
    if(d==0)
    {

      int h=fork();
      if(h==0)
      {
        int i=fork();
        if(i==0)
        {
          printf("\n I:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );

        }
        else
        {
        printf("\n H:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );
       }
      }
    else
    {
      printf("\n D:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );
    }
    }
    else
    {
      int e=fork();
      if(e==0)
      {printf("\n E:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );}
     else
     {
       int f=fork();
       if(f==0)
      {
        printf("\n F:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );

      }
      else
      wait(NULL);
    }

  }
  }
  else
  {

    int c=fork();
    if(c==0)
    {
       printf("\n C:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );

      int g=fork();
      if(g==0)
     {
     printf("\n G:Child process (pid : %d) and (ppid:%d)\n",getpid(),getppid() );
     }
    }
    else
    wait(NULL);
  }
}

#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
void main()
{
  int n;
  printf("\n Enter the value of N : ");
  scanf("%d",&n );

  int value=fork();
  if(value==0)
  {
    printf("\n CHILD PROCESS (PID: %d)",getpid() );
    printf("\n PARENT'S PID: %d",getppid() );
    printf("\n FIBONACCI SERIES : 0 1 " );
    int c=2,first=0,second=1,third=first+second;
    while(third<n)
    {
      printf(" %d ",third );

      first=second;
      second=third;

    third=first+second;
    }


  }
  else if(value>0)
  {
    wait(NULL);
    printf("\n\n PARENT PROCESS (PID: %d)",getpid() );
    printf("\n PRIME NUMBERS : " );
    for(int i=2;i<=n;i++)
    {
      int flag=0;
      for(int j=1;j<=i;j++)
      {
        if(i%j==0)
         flag++;
      }
      if(flag==2)
       printf(" %d ",i );
    }
  }
  else
   printf("\n child not created");

   printf("\n" );
}

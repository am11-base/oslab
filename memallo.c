#include<stdio.h>
#include<stdbool.h>
#define max 100
void worstfit(int block[max],int pro[max],int no_b,int no_p)
{
    bool allocblock[max],allocpro[max];int allocref[max];

    for(int i=0;i<no_b;i++)
     allocblock[i]=false;

    for(int i=0;i<no_p;i++)
      allocpro[i]=false;

      for(int i=0;i<no_p;i++)
      {
        int flag=10000;
        for(int j=0;j<no_b;j++)
        {
          if(allocblock[j]==false&&pro[i]<=block[j])
          {
            if(flag==10000)
             flag=j;
            else if(block[j]>=block[flag])
             flag=j;
          }

        }
        if(flag!=10000)
        {
          allocpro[i]=true;
          allocblock[flag]=true;
          allocref[flag]=i;
        }

      }
      printf("\n\n\t  WORST FIT");
      printf("\n       ~~~~~~~~~~~~~~~~\n\n" );
      for(int i=0;i<no_b;i++)
       printf("|----------");
      printf("|\n");
      for(int i=0;i<no_b;i++)
      {
        printf("|" );
        if(allocblock[i]==true)
        printf("   %d    ",pro[allocref[i]] );
        else
        printf("   NIL    ");

      }
      printf("|\n");
      for(int i=0;i<no_b;i++)
       printf("|----------");
      printf("|\n");
      for(int i=0;i<no_b;i++)
       printf("    %dKB  ",block[i]);

      for(int i=0;i<no_p;i++)
      {
        if(allocpro[i]==false)
         printf("\n\n  %d(P%d) not allocated ",pro[i],i+1 );
      }


}

void bestfit(int block[max],int pro[max],int no_b,int no_p)
{
    bool allocblock[max],allocpro[max];int allocref[max];

    for(int i=0;i<no_b;i++)
     allocblock[i]=false;

    for(int i=0;i<no_p;i++)
      allocpro[i]=false;

      for(int i=0;i<no_p;i++)
      {
        
        int flag=10000;
        for(int j=0;j<no_b;j++)
        {
          if(allocblock[j]==false&&pro[i]<=block[j])
          {
            if(flag==10000)
             flag=j;
            else if(block[j]<=block[flag])
             flag=j;
          }

        }
        if(flag!=10000)
        {
          allocpro[i]=true;
          allocblock[flag]=true;
          allocref[flag]=i;
        }

      }
      printf("\n\n\t  BEST FIT");
      printf("\n       ~~~~~~~~~~~~~~~~\n\n" );
      for(int i=0;i<no_b;i++)
       printf("|----------");
      printf("|\n");
      for(int i=0;i<no_b;i++)
      {
        printf("|" );
        if(allocblock[i]==true)
        printf("   %d    ",pro[allocref[i]] );
        else
        printf("   NIL    ");

      }
      printf("|\n");
      for(int i=0;i<no_b;i++)
       printf("|----------");
      printf("|\n");
      for(int i=0;i<no_b;i++)
       printf("    %dKB  ",block[i]);

      for(int i=0;i<no_p;i++)
      {
        if(allocpro[i]==false)
         printf("\n\n  %d(P%d) not allocated ",pro[i],i+1 );
      }


}
void firstfit(int block[max],int pro[max],int no_b,int no_p)
{
    bool allocblock[max],allocpro[max];int allocref[max];


    for(int i=0;i<no_b;i++)
     allocblock[i]=false;

    for(int i=0;i<no_p;i++)
      allocpro[i]=false;



    for(int i=0;i<no_b;i++)
    {
      for(int j=0;j<no_p;j++)
      {
        if(allocblock[i]==false&&allocpro[j]==false&&pro[j]<=block[i])
        {
          allocblock[i]=true;
          allocpro[j]=true;
          allocref[i]=j;
          break;

        }
      }
    }

    printf("\n\n\t  FIRST FIT");
    printf("\n       ~~~~~~~~~~~~~~~~\n\n" );
    for(int i=0;i<no_b;i++)
     printf("|----------");
    printf("|\n");
    for(int i=0;i<no_b;i++)
    {
      printf("|" );
      if(allocblock[i]==true)
      printf("   %d    ",pro[allocref[i]] );
      else
      printf("   NIL    ");

    }
    printf("|\n");
    for(int i=0;i<no_b;i++)
     printf("|----------");
    printf("|\n");
    for(int i=0;i<no_b;i++)
     printf("    %dKB  ",block[i]);

    for(int i=0;i<no_p;i++)
    {
      if(allocpro[i]==false)
       printf("\n\n  %d(P%d) not allocated ",pro[i],i+1 );
    }
}
void main()
{
  int block[max],process[max],no_b,no_p;
  printf("\n Enter the Number of Memory Blocks : ");
  scanf("%d",&no_b);
  for(int i=0;i<no_b;i++)
  {
    printf(" Enter the Size of Memory Block No %d : ",i+1);
    scanf("%d",&block[i]);
  }
  printf("\n Enter the Number of Process : ");
  scanf("%d",&no_p);
  for(int i=0;i<no_p;i++)
  {
    printf(" Enter the Size of Process No %d : ",i+1);
    scanf("%d",&process[i]);
  }

  firstfit(block,process,no_b,no_p);
  bestfit(block,process,no_b,no_p);
  worstfit(block,process,no_b,no_p);

  printf("\n");
}

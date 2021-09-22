#include<stdio.h>
#include<stdlib.h>
#define maxi 100
typedef struct lru
{
  int data,index,order;
}lru;

void printframes(int fr[],int size)
{
  for(int i=0;i<size;i++)
  {
             if(fr[i]!=-1)
              printf(" %d ",fr[i]);
             else
               break;

    }
    printf("\n");
 }

int search(int key,int fr[],int size)
{
  for(int i=0;i<size;i++)
  {
   if(fr[i]==key)
    return 1;
  }
  return 0;
}
int getpos(int key,lru fr[],int size)
{
  for(int i=0;i<size;i++)
  {
  if(fr[i].data==key)
   return i;
  }
}
int getmaxorder(lru frames[],int size)
{
  int max=0;
  for(int i=1;i<size;i++)
  {

    if(frames[i].order>frames[max].order)
     max=i;

   }
  return max;

}
int getleastorder(lru frames[],int size)
{
  int min=0;
  for(int i=1;i<size;i++)
  {

    if(frames[i].order<frames[min].order)
     min=i;

   }
  return min;

}

void lrual(int ref[],int n,int size)
{
  int count=0,lim=0;
   int *fr=(int *)malloc(sizeof(int)*size);
   printf("\nLeast Recently Used\n");
   lru* frames=(lru*)malloc(sizeof(lru)*size);

   for(int i=0;i<size;i++)
   {
     fr[i]=-1;
     frames[i].data=-1;
     frames[i].index=-1;
     frames[i].order=0;

   }
   for(int i=0;i<n;i++)
   {
     int key=ref[i];
    if(lim<size)
    {
      int found=search(key,fr,size);
      if(found==0)
      {
       fr[lim]=key;
       frames[lim].data=key;
       frames[lim].order=i;
       frames[lim].index=i;


       lim++;
       count++;

       printframes(fr,size);
      }
      else
      {
         int in=getpos(key,frames,size);
         int mf=getmaxorder(frames,size);
         frames[in].order=frames[mf].order+1;

      }
    }
    else
    {
      int found=search(key,fr,size);
      if(found==0)
      {
        int lf=getleastorder(frames,size);
        int mf=getmaxorder(frames,size);
        fr[frames[lf].index]=key;
        frames[lf].data=key;
        frames[lf].order=frames[mf].order+1;

        count++;

        printframes(fr,size);
      }
      else
      {
        int in=getpos(key,frames,size);
        int mf=getmaxorder(frames,size);
        frames[in].order=frames[mf].order+1;
      }
    }
  }
 printf("\n Number of page faults : %d \n ",count);
}
void main()
{
 int reference[maxi],n,size;
 printf("\n Enter the number of page references : ");
 scanf("%d",&n);
 printf("\n Enter the page reference : ");
 for(int i=0;i<n;i++)
  scanf("%d",&reference[i]);
 printf("\n Enter the frame size : ");
 scanf("%d",&size);

 lrual(reference,n,size);
}

#include<stdlib.h>
#include<stdio.h>
#define max 100
typedef struct lfu
{
  int data,index,freq,order;
}lfu;

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
int getpos(int key,lfu fr[],int size)
{
  for(int i=0;i<size;i++)
  {
  if(fr[i].data==key)
   return i;
  }

}
int getleastpos(lfu frames[],int size)
{
  int min=0;
  for(int i=1;i<size;i++)
  {

    if(frames[i].freq<frames[min].freq)
     min=i;
    else if(frames[i].freq==frames[min].freq)
     {
        if(frames[i].order<frames[min].order)
        	min=i;

      }
   }
  return min;



}

void lfual(int refr[],int n,int size)
{
   int count=0,lim=0;
   int *fr=(int *)malloc(sizeof(int)*size);
   printf("\nLeast Frequently Used\n");
   lfu* frames=(lfu*)malloc(sizeof(lfu)*size);

   for(int i=0;i<size;i++)
   {
     fr[i]=-1;
     frames[i].data=-1;
     frames[i].index=-1;
     frames[i].freq=0;
     frames[i].order=0;

   }
   for(int i=0;i<n;i++)
   {
     int key=refr[i];
     if(lim<size)
     {
        int found=search(key,fr,size);
        if(found==0)
        {
         fr[lim]=key;
         frames[lim].data=key;
         frames[lim].index=i;
         frames[lim].freq+=1;
         frames[lim].order=i;

         lim++;
         count++;

         printframes(fr,size);
        }
        else
        {
          int in=getpos(key,frames,size);
          printf("--HIT--\n");
          frames[in].freq+=1;
        }
     }
     else
     {
         int found=search(key,fr,size);
         int lf=getleastpos(frames,size);
         if(found==0)
         {
          fr[frames[lf].index]=key;
          frames[lf].data=key;
          frames[lf].freq=1;
          frames[lf].order=i;
          for(int i=0;i<size;i++)
          {
             if(frames[i].data!=-1)
              printf(" %d ",frames[i].data);
             else
               break;

          }
          printf("\n");
          count++;
         }
         else
         {
          int in=getpos(key,frames,size);
          printf(" --HIT--\n");
          frames[in].freq+=1;
         }
     }
   }

   printf("\n Number of page faults : %d \n ",count);
}
void main()
{
 int reference[max],n,size;
 printf("\n Enter the number of page references : ");
 scanf("%d",&n);
 printf("\n Enter the page reference : ");
 for(int i=0;i<n;i++)
  scanf("%d",&reference[i]);
 printf("\n Enter the frame size : ");
 scanf("%d",&size);

 lfual(reference,n,size);
}

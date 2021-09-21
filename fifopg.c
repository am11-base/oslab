#include<stdio.h>
#define max 100
int queue[max],front=-1,rear=-1;

void insert(int key,int size)
{
  queue[++rear]=key;
  if(rear==size-1)
   rear=-1;
}
void print(int size)
{
  printf("\n ");
  for(int i=0;i<size;i++)
  {
    if(queue[i]!=-1)
     printf(" %d ",queue[i] );
  }
}
int search(int n,int size)
{
  for(int i=0;i<size;i++)
  {
    if(queue[i]==n)
     return 1;
  }
  return 0;
}
void fifo(int ref[max],int n,int size)
{
  printf("\n FIFO \n FRAMES ");
  int front=0,count=0;
  for(int i=0;i<size;i++)
   queue[i]=-1;
  for(int i=0;i<n;i++)
  {
    int in=ref[i];
    int found=search(in,size);
    if(found==0)
    {
       insert(in,size);
       print(size);
       count++;
    }
    else
    {
      printf("\n --- HIT --- ");
    }
  }

  printf("\n page fault : %d \n ",count );
}
void main()
{
  int pageref[max],n,fsize;
  printf("\n Enter the number of page reference : ");
  scanf("%d",&n );
  printf("\n Enter the page reference : ");
  for(int i=0;i<n;i++)
   scanf("%d",&pageref[i] );
  printf("\n Enter the frame size : ");
  scanf("%d",&fsize );

  fifo(pageref,n,fsize);



}

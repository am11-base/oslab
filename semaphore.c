#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int sem=1,full,empty,buffer[20];
int front=-1,rear=-1;
int wait(int val)
{
    return (--val);
}
int signal(int val)
{
    return (++val);
}

void printbuffer()
{
 printf("\n Buffer :");
 for(int i=front;i<=rear;i++)
  printf(" %d ",buffer[i]);
}
void insert(int item)
{
 if(rear==-1)
  front++;
 buffer[++rear]=item;
}
int  delete()
{
 return(buffer[front++]);
}
void producer(int item)
{
    empty=wait(empty);
    sem=wait(sem);
    printf("\n Producer produces %d ",item);
    insert(item);
    sem=signal(sem);
    full=signal(full);
}
void consumer()
{
    full=wait(full);
    sem=wait(sem);
    int item=delete();
    printf("\n Consumer Consumes %d ",item);
    sem=signal(sem);
    empty=signal(empty);
}
void main()
{
    int n,size,item;
    printf("Enter the size of Buffer :");
    scanf("%d",&size);
    full=0;
    empty=size;
    printf("\n  Producer Consumer Problem");
    printf("\n  1.Produce");
    printf("\n  2.Consume");
    printf("\n  3.Exit");
    while(true){
        printf("\n\n  Enter your choice:");
        scanf("%d",&n);
        switch(n){
            case 1:
                if((sem==1)&&(empty!=0)){
                    int item = rand() % 50;
                    producer(item);
                    printbuffer();
                }
                else
                {
                    printf("\n  Buffer is full!!");
                }
                break;
            case 2:
                if((sem==1)&&(full!=0))
                {
                    consumer();
                    printbuffer();
                }
                else{
                    printf("\n  Buffer is empty!!");
                }
                break;
            case 3:
                exit(0);
        }
    }
}

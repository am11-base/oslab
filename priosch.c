#include<stdio.h>
#define max 100
typedef struct process
{
  int pid;
  int at;
  int prio;
  int priocpy;
  int atcpy;
  int bt;
  int wt;
  int tat;

}p;

p pro[100];

int queue[max],front=-1,rear=-1;
void enqueue(int n)
{
  if(rear==max-1)
   printf("\n overflow");
  else{

  if(front==rear)
   front=0;
  queue[++rear]=n;
 }
}
void printstatus(int n,float avgwt,float avgtat)
{
  printf("\n\t   PRINTING STATUS ");
  printf("\n--------------------------------------------------");
  printf("\n Process   BT \t AT \tPRIO \tTAT \t WT  ");
  for(int i=0;i<n;i++)
  {
    printf("\n %d    \t   %d \t %d \t %d \t %d \t %d  ",pro[i].pid,pro[i].bt,pro[i].at,pro[i].prio,pro[i].tat,pro[i].wt);
  }
  printf("\n--------------------------------------------------");

  printf("\n Average Turn around time : %.3f",avgtat);
  printf("\n Average Waiting time     : %.3f",avgwt);
  printf("\n");
}
float calctat(int n)
{
  int cumtat=0;
  for(int i=0;i<n;i++)
  {
    pro[i].tat=pro[i].wt+pro[i].bt;
    cumtat=cumtat+pro[i].tat;
  }
  float avgtat=(float)cumtat/n;

    return avgtat;
}

float calcwt(int n)
{

  int index;
  int count=0;

  for(int i=0;count!=n;i++)
  {
    //comparing both at and bt
    int pr=100;
    for(int j=0;j<n;j++)
    {
      if(pro[j].atcpy<=i && pro[j].priocpy<pr)
      {

        pr=pro[j].priocpy;
        index=j;
      }
    }

    int cumbt=0;
    for(int k=front;k<=rear;k++)
    { cumbt=cumbt+queue[k];}

    //for the least waited
    if(cumbt==0)
    {
     pro[index].wt=0;
     enqueue(pro[index].bt);

    }
    else
    {
      pro[index].wt=cumbt-pro[index].at;
      enqueue(pro[index].bt);
    }
    pro[index].priocpy=100;
    pro[index].atcpy=100;

    //update burst time to iterating variable
    for(int k=front;k<=rear;k++)
    { cumbt=cumbt+queue[k];}

    i=cumbt-1;
    count++;

  }

   //calculating average
   int cumwt=0;
   for(int i=0;i<n;i++)
   {
     cumwt=cumwt+pro[i].wt;
   }

   float avgwt=(float)cumwt/n;

   return avgwt;

}

void main()
{
  int n,index;
  float avgwt,avgtat;
  printf("\n Enter the number of processes : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    printf("\n Process %d",i+1);
    printf("\n Burst time   : ");
    scanf("%d",&pro[i].bt);
    printf(" Arrival time : ");
    scanf("%d",&pro[i].at);
    printf(" Priority     : ");
    scanf("%d",&pro[i].prio);
      pro[i].priocpy=pro[i].prio;
    pro[i].atcpy=pro[i].at;
    pro[i].pid=i+1;
  }

  avgwt=calcwt(n);
  avgtat=calctat(n);
  printstatus(n,avgwt,avgtat);
}

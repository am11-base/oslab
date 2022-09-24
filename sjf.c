#include<stdio.h>
#define max 100
typedef struct process
{
  int pid;
  int at;
  int flag;
  int ct;
  int bt;
  int wt;
  int tat;

}p;

p pro[100];


void printstatus(int n,float avgwt,float avgtat)
{
  printf("\n\t   PRINTING STATUS ");
  printf("\n--------------------------------------------------");
  printf("\n Process   BT \t AT \t TAT \t WT  ");
  for(int i=0;i<n;i++)
  {
    printf("\n %d    \t   %d \t %d \t %d \t %d  ",pro[i].pid,pro[i].bt,pro[i].at,pro[i].tat,pro[i].wt);
  }
  printf("\n--------------------------------------------------");

  printf("\n Average Turn around time : %.3f",avgtat);
  printf("\n Average Waiting time     : %.3f",avgwt);
  printf("\n");
}
float calcwt(int n)
{
  int cumwt=0;
  for(int i=0;i<n;i++)
  {
    pro[i].wt=pro[i].tat-pro[i].bt;
    cumwt=cumwt+pro[i].wt;
  }
  float avgwt=(float)cumwt/n;

    return avgwt;
}

float calcct(int n)
{

  int index,index1,index2,count=0;
  for(int timer=0;count!=n;)
  {
    //finding the least bt

    int minbt=100;
    for(int i=0;i<n;i++)
    {
      if(pro[i].bt<minbt&&pro[i].flag==0)
      {
        minbt=pro[i].bt;
        index1=i;
      }
    }

    //find the least at

    int minat=100;
    for(int i=0;i<n;i++)
    {
      if(pro[i].at<minat&&pro[i].flag==0)
      {
        minat=pro[i].at;
        index2=i;
      }
    }

    if(timer<=minat&&pro[index1].at!=pro[index2].at)
     index=index2;
    else
     index=index1;



    printf("\n index : %d",index );
    if(timer<minat)
      timer=minat;
    timer=timer+pro[index].bt;
    pro[index].ct=timer;    //for the least waited

    pro[index].flag=1;
    count++;
  }
}

float calctat(int n)
{
  int cumtat=0;
  for(int i=0;i<n;i++)
  {
    pro[i].tat=pro[i].ct-pro[i].at;
    cumtat=cumtat+pro[i].tat;
  }
  float avgtat=(float)cumtat/n;

    return avgtat;
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
    pro[i].flag=0;
    pro[i].pid=i+1;
  }

  calcct(n);
  avgtat=calctat(n);
  avgwt=calcwt(n);
  printstatus(n,avgwt,avgtat);
}

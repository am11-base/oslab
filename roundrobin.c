#include <stdio.h>
#define max 100
typedef struct process
{
        int pid;
        int at;
        int bt;
        int rt;
        int ct;
        int wt;
        int tat;
        int flag;
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
        printf("\n Process   BT \t AT \t TAT \t WT  ");
        for(int i=0; i<n; i++)
        {
                printf("\n %d    \t   %d \t %d \t %d \t %d  ",pro[i].pid,pro[i].bt,pro[i].at,pro[i].tat,pro[i].wt);
        }
        printf("\n--------------------------------------------------");

        printf("\n Average Turn around time : %.3f",avgtat);
        printf("\n Average Waiting time     : %.3f",avgwt);
        printf("\n");
}
float calctat(int n)
{
        int cumtat=0;
        for(int i=0; i<n; i++)
        {
                pro[i].tat=pro[i].ct-pro[i].at;
                cumtat=cumtat+pro[i].tat;
        }
        float avgtat=(float)cumtat/n;

        return avgtat;
}

float calcct(int n,int quant)
{

        int count=0,index;
        //ordering least at to queue
        for(int i=0; i<n; i++)
        {


                int minat=100;
                for(int j=0; j<n; j++)
                {
                        if(pro[j].at<minat&&pro[j].flag==0)
                        {
                                minat=pro[j].at;
                                index=j;
                        }
                }
                enqueue(index);
                pro[index].flag=1;
        }


        printf("\n QUEUE : ");
        for(int i=front; i<=rear; i++)
        {
                printf(" %d ",queue[i] );
        }

//main
        for(int timer=0; count!=n;)
        {
                int i=front;
                for(int i=front; i<=rear; i++)
                {
                        if(timer<pro[queue[i]].at)
                                timer=pro[queue[i]].at;
                        if(pro[queue[i]].rt!=0)
                        {
                                if(pro[queue[i]].rt>quant)
                                {
                                        timer+=quant;
                                        pro[queue[i]].rt-=quant;
                                }
                                else
                                {
                                        timer+=pro[queue[i]].rt;
                                        pro[queue[i]].ct=timer;
                                        pro[i].rt=0;
                                        count++;
                                }
                        }
                }
        }
}

float calcwt(int n)
{
        int cumwt=0;
        for(int i=0; i<n; i++)
        {
                pro[i].wt=pro[i].tat-pro[i].bt;
                cumwt=cumwt+pro[i].wt;
        }
        float avgwt=(float)cumwt/n;

        return avgwt;
}
void main()
{
        int n,quant;
        float avgwt,avgtat;
        printf("\n Enter the number of processes : ");
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
                printf("\n Process %d",i+1);
                printf("\n Burst time   : ");
                scanf("%d",&pro[i].bt);
                printf(" Arrival time : ");
                scanf("%d",&pro[i].at);
                pro[i].rt=pro[i].bt;
                pro[i].pid=i+1;
                pro[i].flag=0;
        }
        printf("\n Time Quantum : ");
        scanf("%d",&quant );


        calcct(n,quant);
        avgtat=calctat(n);
        avgwt=calcwt(n);
        printstatus(n,avgwt,avgtat);
}

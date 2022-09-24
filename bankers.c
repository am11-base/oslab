#include <stdio.h>
#include <stdlib.h>
#define max 100
void calcneed(int alloc[max][max],int maxi[max][max],int need[max][max],int n_p,int n_r)
{
        for(int i=0; i<n_p; i++)
                for(int j=0; j<n_r; j++)
                        need[i][j]=maxi[i][j]-alloc[i][j];

}
void safealg(int alloc[max][max],int need[max][max],int avail[max],int n_p,int n_r)
{
        int safe[max],finish[max],flag;
        int count=0;

        printf("\n Safe sequenece : ");


        for(int i=0; i<n_p; i++)
                finish[i]=0;

        while(count<n_p)
        {
                flag=0;
                for(int i=0; i<n_p; i++)
                {
                        if(finish[i]==0)
                        {

                                int j;
                                for(j=0; j<n_r; j++)
                                {
                                        if(need[i][j]>avail[j])
                                                break;
                                }

                                if(j==n_r)
                                {
                                        for(int k=0; k<n_r; k++)
                                                avail[k]+=alloc[i][k];


                                        safe[count]=(i+1);
                                        count++;
                                        finish[i]=1;
                                        flag=1;
                                }
                        }
                }

                if(flag==0)
                {  printf("\n Process are not in safe state \n");
                   break;}

        }
        if(flag!=0)
        {
                for(int i=0; i<n_p; i++)
                        printf("P %d ->",safe[i] );
                printf("\n");
        }

}

void resourcereq(int alloc[max][max],int need[max][max],int avail[max],int n_p,int n_r)
{
        int req[max];
        int proid;
        printf("Enter the process which wants to make request : ");
        scanf("%d",&proid);
        printf("\n Enter the request : " );
        for(int i=0; i<n_r; i++)
                scanf("%d",&req[i]);
        for(int i=0; i<n_r; i++)
        {
                if(req[i]>need[proid-1][i])
                {
                        printf("\n Request is greater than need");
                        exit(0);
                }
        }
        for(int i=0; i<n_r; i++)
        {
                if(req[i]>avail[i])
                {
                        printf("\n Request is greater than available");
                        exit(0);
                }
        }
        for(int i=0; i<n_r; i++)
        {
                avail[i]-=req[i];
                need[proid-1][i]-=req[i];
                alloc[proid-1][i]+=req[i];
        }
        safealg(alloc,need,avail,n_p,n_r);


}

void main()
{
        int alloc[max][max],maxi[max][max],need[max][max],avail[max];
        int n_p,n_r,choice;
        printf("\n\t Bankers Safe Algorithm");
        printf("\n----------------------------------------------------------");
        printf("\n Enter the number of process : ");
        scanf("%d",&n_p );
        printf("\n Enter the number of resources : ");
        scanf("%d",&n_r );
        printf("\n Enter the allocation matrix : \n ");
        for(int i=0; i<n_p; i++)
                for(int j=0; j<n_r; j++)
                        scanf("%d",&alloc[i][j] );
        printf("\n Enter the Maximum matrix : \n");
        for(int i=0; i<n_p; i++)
                for(int j=0; j<n_r; j++)
                        scanf("%d",&maxi[i][j] );
        printf("\n Enter available array : ");
        for(int i=0; i<n_r; i++)
                scanf("%d",&avail[i] );

        calcneed(alloc,maxi,need,n_p,n_r);

        printf("\n 1.Safety Algorithm 2.Resouce request \n Enter your choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
                safealg(alloc,need,avail,n_p,n_r);
        }else if(choice==2)
        {
                resourcereq(alloc,need,avail,n_p,n_r);
        }
}

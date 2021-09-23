#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include<stdbool.h>
key_t key;
sem_t empty,full;
pthread_mutex_t sem;

pthread_t pid,cid;
int shmid,size,front=-1,rear=-1;
void insert(int buffer[],int item)
{
 if(rear==-1)
  front++;
 buffer[++rear]=item;
}
void printbuffer(int buffer[])
{
 printf("\n Buffer :");
 for(int i=front;i<=rear;i++)
  printf(" %d ",buffer[i]);
}

int  delete(int buffer[])
{
 return(buffer[front++]);
}
void produce()
{
	   int *buffer = (int*) shmat(shmid, (void*) 0, 0);

		int item = rand() % 100;

		//sleep(1);
		sem_wait(&empty);
		pthread_mutex_lock(&sem);

		printf("\n Producer produces %d ",item);
        insert(buffer,item);


		pthread_mutex_unlock(&sem);
		sem_post(&full);

		printbuffer(buffer);

	shmdt(buffer);
}

void consume() {

	   int *buffer = (int*) shmat(shmid, (void*) 0, 0);

		sem_wait(&full);
		pthread_mutex_lock(&sem);

    int item=delete(buffer);
    printf("\n Consumer Consumes %d ",item);

		pthread_mutex_unlock(&sem);
		sem_post(&empty);

	    printbuffer(buffer);
	shmdt(buffer);
}

void main()
{
  int n;
 key=ftok("shmpro",9);
 shmid=shmget(key,1024,IPC_CREAT|0666);

 printf("\n Enter Buffer Size : ");
 scanf("%d",&size);


 sem_init(&empty,0,size);
 sem_init(&full,0,0);
 pthread_mutex_init(&sem,NULL);

  printf("\n  Producer Consumer Problem");
    printf("\n  1.Produce");
    printf("\n  2.Consume");
    printf("\n  3.Exit");
    while(true){
        printf("\n\n  Enter your choice:");
        scanf("%d",&n);
        switch(n){
            case 1:
            int a;
              sem_getvalue(empty,a);
              printf("\n %d",a );

                pthread_create(&pid, NULL, (void*) produce, NULL);
                sleep(1);


                break;
            case 2:

                {
                 pthread_create(&cid, NULL, (void*) consume, NULL);
                 sleep(1);
                 }

               break;
            case 3:
                exit(0);
        }
    }
    	//pthread_join(pid, NULL);
    	//pthread_join(cid, NULL);

    sem_destroy(&full);
    	sem_destroy(&empty);
    	pthread_mutex_destroy(&sem);
	shmctl(shmid, IPC_RMID, NULL);
 }

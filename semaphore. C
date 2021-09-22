#include<stdio.h>
int mutex=1,full,empty,buffer[20];

int wait(int val){
    return (--val);
}
int signal(int val){
    return (++val);
}
void producer(int item){
    empty=wait(empty);
    mutex=wait(mutex);
    buffer[full]=item;
    printf("  Producer produces the item %d",item);
    mutex=signal(mutex);
    full=signal(full);
}
void consumer(){
    full=wait(full);
    mutex=wait(mutex);
    int item = buffer[full];
    printf("  Consumer consumes item %d",item);
    mutex=signal(mutex);
    empty=signal(empty);
}
void main(){
    int n,size,var=1,item;
    printf("Enter the size of Buffer :");
    scanf("%d",&size);
    full=0;
    empty=size;
    printf("\nProducer Consumer Problem");
    printf("\n  1.Produce");
    printf("\n  2.Consume");
    printf("\n  3.Exit");
    while(var==1){
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n){
            case 1:
                if((mutex==1)&&(empty!=0)){
                    printf("  Enter item to add in Buffer : ");
                    scanf("%d",&item);
                    producer(item);
                }else{
                    printf("  Buffer is full!!");
                }break;
            case 2:
                if((mutex==1)&&(full!=0)){
                    consumer();
                }else{
                    printf("  Buffer is empty!!");
                }break;
            case 3:
                var=0;
                break;
        }
    }
}


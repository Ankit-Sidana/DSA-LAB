#include<stdio.h>

int adult = 0 ,child = 0,vip[],i,vtemp;
struct queue{int arr[20],first,last;}p;
int isfull(){
    if(p.last==19){
    return 1;
    }
    else{
    return 0;
    }
}

int isempty(){
    if(p.last==-1){
        return 1;
    }
    else{
    return 0;
    }
}

void enqueue(){
    int n;
    printf("\n Is it an adult or a child (1-ADULT,2-CHILD): \n");
    scanf("%d",&n);
    if(n == 1){
        adult++;
    }
    else if(n==2){
        child++;
    }
    else{
        printf("\nPlease choose the correct value.\n");
        return;
    }
    printf("Enter rider number\n");
    scanf("%d",&n);
    if(isfull()==0) 
    p.arr[++p.last]=n;
    else{
        printf("Queue is full\n");
    }
}

void dequeue(){
    if(isempty()==0){
        printf("Rider number %d is allowed on to the roller coaster\n",p.arr[p.first]);
        p.first++;
    }
    else{
        printf("There are no people in queue\n");
    }
}

void main(){
    p.first=0;
    p.last=-1;
    int choice,d;
    while(choice!=6){
        printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n");
        printf("\tEnter 1 to place person in queue\n");
        printf("\tEnter 2 to check if queue is full and to allow all riders to enter the roller coaster\n");
        printf("\tEnter 3 to see all riders in queue\n");
        printf("\tEnter 4 to See the number of adults and children.\n");
        printf("\tEnter 5 to enter the VIP member.\n");
        printf("\tEnter 6 to exit\n");
        printf("\nEnter your choice:- ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                enqueue();
                break;
            }
            case 2: {
                if(isfull()==1){
                    int i;
                    for(i=0;i<20;i++){
                        dequeue();
                    }
                }
                else{
                    printf("Queue does not consist of enough members and the ride cannotstart\n");
                }
                break;
            }
            case 3:{
                int i;
                for(i=0;i<=p.last;i++){
                    printf("%d \n",p.arr[i]);
                }
            break;
            }
            printf("\n");
            case 4:{
                printf("There are %d adults and %d children.\n",adult,child);
                break;
            }
            case 5:{
                int n;
                printf("\n Is it an adult or a child (1-ADULT,2-CHILD): \n");
                scanf("%d",&n);
                if(n == 1){
                    adult++;
                }
                else if(n==2){
                    child++;
                }
                else{
                    printf("\nPlease choose the correct value.\n");
                    break;
                }
                printf("Enter the VIP number.");
                scanf("%d",&vtemp);
                for (i = 20; i >= 0; i--){
                    p.arr[i] = p.arr[i - 1];
                }
                p.arr[0] = vtemp;
                p.last++;
                break;
            }
            case 6:{
                printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("HAVE a NICE DAY!!!!\n");
                break;
            }   
        }
    }
}

#include<stdio.h>
#include<stdlib.h>

struct node{
    int id;
    int s;
    float time;
    struct node *next;
};
struct node *top=NULL,*delay=NULL;

int isempty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter Truck ID\n");
    scanf("%d",&temp->id);
    printf("Enter Service No.\n");
    scanf("%d",&temp->s);
    printf("Enter time required for each service\n");
    scanf("%f",&temp->time);
    if (isempty()){
        temp->next=NULL;
        top=temp;
    }
    else{
        temp->next=top;
        top=temp;
    }
}

void pop(){
    struct node *temp;
    int x,y;
    float z;
    if(isempty())
        printf("There are no trucks, the garage is empty\n");
    else{
        x=top->id;
        y=top->s;
        z=top->time;
        temp=top;
        top=temp->next;
        free(temp);
        printf("The truck with id %d, serice no. %d, time required %f is serviced and can go out\n",x,y,z);
    }
}

float max(){
    struct node *temp;
    float max=top->time;
    temp=top;
    while(temp->next!=NULL){
        if(temp->time>=max)
        max=temp->time;
        temp=temp->next;
    }
    if(temp->time>max)
        max=temp->time;
    return(max);
}

void display(){
    struct node *temp=top;
    if(isempty())
        printf("Garage is empty\n");
    else{
        while(temp->next!=NULL){
            printf("There is a truck with id %d, service no. %d, time required %f in the garage\n\n",temp->id,temp->s,temp->time);
            temp=temp->next;
        }
    printf("There is a truck with id %d, service no. %d, time required %f in the garage\n\n",temp->id,temp->s,temp->time);
    }
}

void display1(){
    struct node *temp=delay;
    if(delay==NULL)
        printf("There is no truck whose service is postponed");
    else{
        while(temp->next!=NULL){
            printf("There is a truck with id %d, service no. %d, time required %f in the garage\n\n",temp->id,temp->s,temp->time);
            temp=temp->next;
        }
    printf("There is a truck with id %d, service no. %d, time required %f in the garage\n\n",temp->id,temp->s,temp->time);
    }
}

void main(){
    struct node *temp1;
    int ch;
    float m;
    while(ch!=6){
        printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n");
        printf("\t1-To allow the entry of truck\n");
        printf("\t2-Exit of trucks near the entry gate \n");
        printf("\t3-Display the details of the trucks in the garage(left to be serviced)\n");
        printf("\t4-Display the details of the trucks whose service has been postponed\n");
        printf("\t5-Display the details of the truck near the entry gate\n");
        printf("\t6-Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                printf("only the truck near the gate is serviced\n");
                m=max();
                if(top->time!=m){
                    if(top->s<=3)
                        printf("Service is FREE\n");
                    else if(top->s>3)
                    printf("Unfortunately there is a charge\n");
                pop();
                }
                else if(top->time==m){
                    printf("Postponed because it requires a LOT of time.\n");
                    temp1=top;
                    top=top->next;
                    if(delay==NULL){
                        delay=temp1;
                        delay->next=NULL;
                    }
                    else{
                        temp1->next=delay;
                        delay=temp1;
                    }
                }
                break;
            case 3:
                display();
                break;
            case 4:
                display1();
                break;
            case 5:
                printf("The details of the truck which entered the garage at last are:\n");
                printf("ID:%d\nSERVICE NO.:%d\nTIME REQD.:%f\n",top->id,top->s,top->time);
                break;
            case 6:
                break;
        }
    }
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You");
}


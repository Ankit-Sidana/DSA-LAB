#include<stdio.h>
# define MAX 20

int stack[MAX], top = -1;

int isfull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int push(int x){
    if(isfull())
        printf("\tStack is full\n");
    else{
        top++;
        stack[top]=x;
    }
}

int isempty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int pop(){
    if(isempty()){
        printf("\tStack is empty\n");
    }
    else{
        int x = 0;
        x=stack[top];
        top=top-1;
        return x;
    }
}

int main(){
    int n,i,a=0,temp=0,chk_even=0,sum=0,ele=0;
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    do{
        printf("\nEnter the no. ");
        scanf("%d",&n);
        if (n%2 != 0)
            push(n);
        else{
            chk_even += 1;
            a = pop();
            temp = n + a;
            push(temp);
        }
        ele += 1;
    
        
    }while(chk_even != 3);
    
    printf("\nYou have entered 3 even numbers.");
    while(top != -1)
        sum += pop();
    printf("\nSum of all the entered numbers is = %d", sum);
    printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You");
    return 0;
}


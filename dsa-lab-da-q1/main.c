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
    int n,ch,no,i,j,stu,che,ver,f=0;
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("\nEnter the no. of students (>=10) : ");
    scanf("%d",&stu);
    for(j=0;j<stu;j++){
        printf("Enter the registeration number of student %d:",top+2);
        scanf("%d",&no);
        push(no);
    }
    int nos=top;
    for(i=nos;i>9;i--)
    pop();
    printf("\nRegisteration numbers of the 10 students who submitted first: \n");
    for(i=9;i>-1;i--){
        printf("\t%d\n",pop());
    }
    printf("\nRegisteration number of last submitted record: ");
    for(i=0; stack[i] != '\0';i++);
        printf("%d\n",stack[--i]);
    printf("\nWould u like to check whether a specific student has submitted the assignment \n\t1 for yes\n\tany other for no \n");
    scanf("%d",&che);
    if(che == 1){
        printf("\nEnter a registeration number to check whether that student has submitted the assignment: ");
        scanf("%d",&ver);
        for(i=0;i<=stu;i++){
            if(stack[i] == ver){
               f = 1;
               break; 
            }
        }
        if (f == 1)
            printf("\nThe Student with registeration number %d has submitted the assignment", ver);
        else
            printf("\nThe Student with registeration number %d has NOT submitted the assignment", ver);
    }
    printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You");
    return 0;
}

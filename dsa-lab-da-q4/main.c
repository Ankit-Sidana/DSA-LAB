#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
static int top;
static char inp[SIZE];
void push(char e){
    top++;
    if(top>=SIZE){
        printf("Overflow");
    }
    else{
        inp[top]=e;
    }
}

char pop(){
    if(top==-1){
        return '\0';
    }
    else{
        char a=inp[top];
        top--;
        return a;
    }
}

int main(){
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nEnter Expression : \n");
    scanf("%s",inp);
    int i=0,f=1,c1=0;
    top=-1;
    while(inp[i]!='\0'){
        if(inp[i]=='{'|| inp[i]=='['|| inp[i]=='('){
            push(inp[i]);
        }
        else if(inp[i]=='}'|| inp[i]==']'|| inp[i]==')'){
            char c=pop();
            if(((c=='['&& inp[i]==']')||(c=='{'&& inp[i]=='}')||(c=='('&&inp[i]==')'))&&f!=0){
                i++;
                continue;
            }
            else{
                f=0;
                c1++;
            }
        }
        else{
            i++;
            continue;
        }
    i++;
    }
    if(top!=-1){
        f=0;
        c1=top+1;
    }
    if(f==0)
        printf("\nInvalid Expression : %d brackets not balanced",c1);
    else
        printf("\nValid Expression\n");
    printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You")
    return 0;
}

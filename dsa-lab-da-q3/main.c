#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define SIZE 50

char s[SIZE]; int top=-1;
char infx[50],prfx[50],ch,elem,pofx[50];
int i=0,k=0;

char *lol(char *str){
    char *p1, *p2;
    if (! str || ! *str)
    return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

void push(char elem){
    s[++top]=elem;
}

char pop(){
    return(s[top--]);
}
int pr(char elem){
    switch(elem){
        case '#': return 0;
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
    }
}

void main() {
    int z;
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("\nPlease enter 1 for REVERSE-POLISH Notation (postfix)\nPlease enter 2 for POLISH Notation (prefix)\n");
    scanf("%d",&z);
    switch(z) {
        case 1:
            printf("\n\tInfix to Postfix");
            printf("\n\nPlease give the Infix Expression- "); 
            scanf("%s",infx); push('#');
            while( (ch=infx[i++]) != '\0') {
                if( ch == '(')
                    push(ch);
                else if(isalnum(ch))
                    pofx[k++]=ch;
                else
                    if( ch == ')') {
                        while( s[top] != '(')
                            pofx[k++]=pop();
                        elem=pop();
                    }
                    else {
                        while( pr(s[top])>=pr(ch) )
                            pofx[k++]=pop();
                            push(ch);
                    }
            }
            while( s[top] != '#')
                pofx[k++]=pop();
            pofx[k]='\0';
            printf("\n\nThe given INFIX expression   %s   converted to POSTFIX is:-   %s\n",infx,pofx);
            break;
        case 2:
            printf("\n\tInfix to Prefix");
            printf("\n\nPlease give the Infix Expression- ");
            scanf("%s",infx); push('#');
            lol(infx);
            while( (ch=infx[i++]) != '\0') {
                if( ch == ')')
                    push(ch);
                else if(isalnum(ch))
                    prfx[k++]=ch;
                else if( ch == '(') {
                    while( s[top] != ')')
                        prfx[k++]=pop();
                    elem=pop();
                }
                else{
                    while( pr(s[top]) >= pr(ch) )
                        prfx[k++]=pop();
                    push(ch);
                }
            }
            while( s[top] != '#')
                prfx[k++]=pop();
            prfx[k]='\0';
            lol(prfx);
            lol(infx);
            printf("\n\nThe given INFIX expression   %s   converted to PREFIX is:-   %s\n",infx,prfx);
    }
    printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You");
}


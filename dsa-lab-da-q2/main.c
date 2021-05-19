#include<stdio.h>
#define MAX 100
#define null 0
int fwd[MAX],back[MAX],t1=-1,t2=-1,item;

void pushback(int item){
	if(t1+1>=MAX) 
        printf("\nOverflow\n");
	else{
		t1++;
		back[t1]=item;
	}
}
void pushfwd(int item){
	 if(t2+1>=MAX) 
        printf("\nOverflow\n"); 
    else{ 
        t2++; 
        fwd[t2]=item;
	}
}
int popback(){
	if(t1==-1){
		return null;
	}
	else{
		item=back[t1];
 		t1--;
 		return item;
	}
}

int popfwd(){
	if(t2==-1)
		return null;
	else{
		item=fwd[t2];
		t2--;
		return item;
	}
}

void display(){
	int i;
	printf("BACKWARD STACK LIST\n");
	for(i=0;i<=t1;i++)
		printf("%d\n",back[i]);
	printf("FORWARD STACK LIST\n");
	for(i=0;i<=t2;i++)  
		printf("%d\n",fwd[i]);

}
int main(){
	printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n");
	int ch,cp=1,x;
	do{
		printf("\n\t1. go forward  2. go backward  3.display 4. exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				pushback(cp);
				cp++;
				if(t2!=-1){
					x=popfwd();
					printf("You are on %d page\n",x); 
				}
				else
					printf("You are on %d page\n",cp);
				break;
			case 2:
				if(cp==1){
					printf("You are on First page");
					break;
				}
				else{
					pushfwd(cp);
					cp--;
					x=popback();
					printf("You are on %d page\n",x);
				}
				break;
			case 3: 
				if(t2!=-1 || t1!=-1)
					display();
				else
					printf("No content for Display"); 
			case 4:
				break;
		}
	}while(ch!=4);
	printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You");
	return 0;
}

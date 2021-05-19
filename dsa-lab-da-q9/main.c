#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

struct node{
    int regNum;
    char sname[max];
    float qzmrks;
    struct node *next;
};
struct node* listA = NULL;
struct node* listB = NULL;
struct node* listM = NULL;

void insertA(int rNum,char nm[max],float mk){
    struct node* newnode = NULL;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->regNum = rNum;
    strcpy(newnode->sname, nm);
    newnode->qzmrks = mk;
    newnode->next = NULL;
    if(listA == NULL)
        listA = newnode;
    else{
        struct node* temp = listA;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void insertB(int rNum,char nm[max],float mk){
    struct node* newnode = NULL;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->regNum = rNum;
    strcpy(newnode->sname, nm);
    newnode->qzmrks = mk;
    newnode->next = NULL;
    if(listB == NULL)
        listB = newnode;
    else{
        struct node* temp = listB;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void insertM(int rNum,char nm[max],float mk){
    struct node* newnode = NULL;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->regNum = rNum;
    strcpy(newnode->sname, nm);
    newnode->qzmrks = mk;
    newnode->next = NULL;
    if(listM == NULL)
        listM = newnode;
    else{
        struct node* temp = listM;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}


void sortA(){
    struct node* i=listA;
    for(i=listA; (i->next)!=NULL; i=i->next){
        struct node* min = i;
        struct node* j=i->next;
        for(j=i->next; j!=NULL; j=j->next){
            if(j->regNum < min->regNum)
                min = j;
        }
        int r = i->regNum;
        i->regNum = min->regNum;
        min->regNum = r;
        
        char n[max]; 
        strcpy(n,i->sname);
        strcpy(i->sname, min->sname);
        strcpy(min->sname, n);
        
        float f = i->qzmrks;
        i->qzmrks = min->qzmrks;
        min->qzmrks = f;
    }
}

void sortB(){
    struct node* i=listB;
    for(i=listB; (i->next)!=NULL; i=i->next){
        struct node* min = i;
        struct node* j=i->next;
        for(j=i->next; j!=NULL; j=j->next){
            if(j->regNum < min->regNum)
                min = j;
        }
        int r = i->regNum;
        i->regNum = min->regNum;
        min->regNum = r;
        
        char n[max];
        strcpy(n,i->sname);
        strcpy(i->sname, min->sname);
        strcpy(min->sname, n);
        
        float f = i->qzmrks;
        i->qzmrks = min->qzmrks;
        min->qzmrks = f;
    }
}

void MergeLists(){
    struct node* temp1 = listA;
    struct node* temp2 = listB;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->regNum < temp2->regNum){
            insertM(temp1->regNum,temp1->sname,temp1->qzmrks);
            temp1 = temp1->next;
        }
        else{
            insertM(temp2->regNum,temp2->sname,temp2->qzmrks);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        insertM(temp1->regNum,temp1->sname,temp1->qzmrks);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        insertM(temp2->regNum,temp2->sname,temp2->qzmrks);
        temp2 = temp2->next;
    }
}

void DisplayA(){
    if(listA == NULL){
        printf("\nList is empty!\n");
        return;
    }
    else{
        struct node* temp = listA;
        printf("\tSET-A\n");
        while(temp != NULL){
            printf("\tRegistration Number : %d\n",temp->regNum);
            printf("\tStudent Name : %s\n",temp->sname);
            printf("\tQuiz Marks : %f\n",temp->qzmrks);
            temp = temp->next;
            printf("\n");
        }
        printf("\n");
    }
}

void DisplayB(){
    if(listB == NULL){
        printf("\nList is empty!\n");
        return;
    }
    else{
        struct node* temp = listB;
        printf("\tSET-B\n");
        while(temp != NULL){
            printf("\tRegistration Number : %d\n",temp->regNum);
            printf("\tStudent Name : %s\n",temp->sname);
            printf("\tQuiz Marks : %f\n",temp->qzmrks);
            temp = temp->next;
            printf("\n");
        }
        printf("\n");
    }
}


void DisplayMergedList(){
    if(listM == NULL){
        printf("\nList is empty!\n");
        return;
    }
    else{
        struct node* temp = listM;
        printf("\tMerged data of SET-A & SET-B in a Sorted manner \n\n");
        while(temp != NULL){
            printf("\tRegistration Number : %d\n",temp->regNum);
            printf("\tStudent Name : %s\n",temp->sname);
            printf("\tQuiz Marks : %f\n",temp->qzmrks);
            temp = temp->next;
            printf("\n");
        }
        printf("\n");
    }
}

int main(){
    int ch;
    while(ch!=9){
        int rno;
        char n[max];
        float m;
        printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
        printf("\tEnter 1 to Insert details for SET-A\n");
        printf("\tEnter 2 to Insert details for SET-B\n");
        printf("\tEnter 3 to Display data of SET-A \n");
        printf("\tEnter 4 to Display data of SET-B.\n");
        printf("\tEnter 5 to Sort data of SET-A.\n");
        printf("\tEnter 6 to Sort data of SET-B.\n");
        printf("\tEnter 7 to MERGE data of SET-A & SET-B in a Sorted manner.\n");
        printf("\tEnter 8 to Display Merged data of SET-A & SET-B in a Sorted manner.\n");
        printf("\tEnter 9 to Exit.\n");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch(ch){
            case 1: {
                printf("\tRegistration Number : ");
                scanf("%d",&rno);
                printf("\tStudent Name : ");
                scanf("%s",n);
                printf("\tQuiz Marks : ");
                scanf("%f",&m);
                insertA(rno,n,m);
                break;
            }
            case 2: {
                printf("\tRegistration Number : ");
                scanf("%d",&rno);
                printf("\tStudent Name : ");
                scanf("%s",n);
                printf("\tQuiz Marks : ");
                scanf("%f",&m);
                insertB(rno,n,m);
                break;
            }
            case 3:{
                DisplayA();
                break;
            }
            case 4:{
                DisplayB();
                break;
            }
            case 5:{
                sortA();
                printf("\nData of SET-A Sorted!!");
                break;
            }
            case 6:{
                sortB();
                printf("\nData of SET-B Sorted!!");
                break;
            }
            case 7:{
                MergeLists();
                printf("\nData of SET-A & SET-B MERGED in a Sorted manner!!\n");
                break;
            }
            case 8:{
                DisplayMergedList();
                break;
            }
            case 9:{
                printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("Thank You!!!\n");
                break;
            }
            default:{
                printf("\nPlease Enter a Valid Choice -_- !!\n");
                break;
            }
        }
    }
    return 0;
}








#include<stdio.h>
#include<stdlib.h>
int search,number=0,i,lz=1;

struct node {
    int info;
    char name[30];
    int marks;
    struct node *prev, *next;
};
struct node* start = NULL;
struct node* first = NULL;
struct node* last = NULL;
struct node* ptr,prev;
void traverse()
{
    struct node* temp1;
    if (first == last && first == NULL)
        printf("\nList is empty\n");
    else{
        
        for (temp1 = first,i = 0;i < number;i++,temp1 = temp1->next){
            printf("\n\n Roll = %d\t Marks = %d\t NAME = ",temp1->info,temp1->marks);
            for(int i = 0;i<(sizeof(temp1->name)/sizeof(temp1->name[0]));i++){
                printf("%c",temp1->name[i]);
            }
        }
    }
}
void n_traverse()
{
    struct node* temp1;
    if (first == last && first == NULL)
        printf("\nList is empty\n");
    else{
        
        for (temp1 = first,i = 0;i < number;i++,temp1 = temp1->next){
            printf("\n\nPosistion %d.-\n",i+1);
            printf("\n\n Roll = %d\t Marks = %d\t NAME = ",temp1->info,temp1->marks);
            for(int i = 0;i<(sizeof(temp1->name)/sizeof(temp1->name[0]));i++){
            printf("%c",temp1->name[i]);
            
        }
            
        }
        
    }
}

void searchRoll(int roll){
    struct node* temp;
    if (first == last && first == NULL)
        printf("\nList is empty\n");
    
    else{
        temp = first;
        int flag  = 0,i = 0 ;
        while(i<number){
            if(roll == temp->info){
                int y = temp->next->info;
                int z = temp->prev->info;
                int m1 = temp->next->marks;
                int m2 = temp->prev->marks;

                printf("\nPrevious ROLL->%d\nPrevious Marks->%d\n\n",z,m2);
                printf("Previous Name: ");
        
                for(int i = 0;i<(sizeof(temp->prev->name)/sizeof(temp->prev->name[0]));i++){
                    printf("%c",temp->prev->name[i]);
                }
                printf("\n\n\n");
        
                
                printf("\nNext ROLL->%d\nNEXT Marks->%d\n\n",y,m1);
                printf("Next Name: ");
                for(int i = 0;i<(sizeof(temp->next->name)/sizeof(temp->next->name[0]));i++){
                    printf("%c",temp->next->name[i]);
                }
                printf("\n\n\n");
                flag  = 1;
                break;
            }
            temp = temp->next;
            i++;
        }
        if(flag == 0){
            printf("\nThe element does not exist.");
        }
    }
}

void insert(){   
    number++;
    int data,marks;
    char tname[30];
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter Roll number : ");
    scanf("%d", &data);
    temp->info = data;
    printf("Enter the Name of the student: ");
    scanf("%s",tname);
    printf("Enter the MARKS obtained: ");
    scanf("%d",&marks);
    temp->marks = marks;
    

    for(int i = 0;tname[i]!=0;i++){
        temp->name[i] = tname[i];
    }
    temp->next = NULL;
    

     if (first == last && first == NULL)
    {
        printf("\nInitially the list is empty and now new node is inserted at first");
        first = last = temp;
        first->next = last->next = NULL;    
        first->prev = last->prev = NULL;
    }
    else
    {   printf("Processing...");
        printf("->%d->%d\n",temp->info,temp->marks);
        last->next = temp;
        temp->prev = last;
        last = temp;
        first->prev = last;
        last->next = first;
    }

}

void delete_node_position(){
    int pos, count = 0, i;
    struct node *temp, *prevnode;
 
    printf("\n\nEnter the position which u want to delete:");
    scanf("%d", &pos);
 
    if (first == last && first == NULL)
        printf("\n Linked list is empty , deletion not possible!");
 
    else
    {
        if (number < pos)
            printf("\n Node cannot be deleted at position as it is exceeding the linkedlist length");
 
        else
        {
            for (ptr = first,i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {    
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("\n%d is deleted!!", prevnode->info);
                    free(prevnode);
                    break;        
                }
                else if (i == pos - 1)
                {    
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("\n%d is deleted!!", ptr->info);
                    free(ptr);
                    break;
                }
            }
        }
    }
}


int main(){
    int choice;
    while (1) {
        printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n");
        printf("\t1  To view List\n");
        printf("\t2  For Insertion \n");
        printf("\t3  Search Element\n");
        printf("\t4  Delete specific element \n");
        printf("\t5  Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insert();
            break;
        case 3:
            printf("\nEnter the INFO to be searched :");
            scanf("%d",&search);
            searchRoll(search);
            break;
        case 4:
            n_traverse();
            delete_node_position();
            break;
        case 5:
            printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
            printf("Thank You!!!\n");
            exit(1);
            break;
        default:
            printf("\nPlease Enter a Valid Choice -_- !!\n");
            break;
        }
    }
    return 0;
}





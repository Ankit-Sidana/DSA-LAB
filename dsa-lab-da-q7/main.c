#include<stdio.h>
#define max 5

int front = -1, rear = -1;
char buf[max],DVD[100];
int n = 0;
int isempty (){
    if (front == -1)
        return 1;
    else
        return 0;
}
int isfull (){
    if (front == (rear + 1) % max)
        return 1;
    else
        return 0;
}
int enqueue (char x) {
    if (isfull ()){
        printf ("The Buffer is full\n");
        return 0;
    }
    if (front == -1){
        rear = 0;
        front = 0;
    }
    else{
        rear = (rear + 1) % max;
    }
    buf[rear] = x;
    return x;
}

char dequeue () {
    char x;
    if (isempty ()){
        printf ("The Buffer is empty\n");
        return 0;
    }
    x = buf[front];
    if (front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front + 1) % max;
    }
    return x;
}
void display (){
    int i = front;
    if (isempty ()){
        printf ("The Buffer is empty\n");
    }
    else{
        while (i != rear){
        printf ("%c\n", buf[i]);
            i = (i + 1) % max;
        }
    printf ("%c\n", buf[i]);
    }
}

void display1 (){
    int k = 0;
    for (k = 0; k < n; k++)
        printf ("%c\n", DVD[k]);
}

void main (){
    char s[100], a, c;
    int ch = 0, j = 0, y = 0, k = 0;
    printf("\n*****************************************");
    printf ("\n\nEnter the data to be burned Into the disk.\n");
    gets(s);
    while (ch != 7){
        printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n");
        printf("\t1-Read the char and store it in buffer\n");
        printf("\t2-Write into DVD\n");
        printf("\t3-Display the current contents of buffer(i.e. valuse not yet burnt)\n");
        printf("\t4-Display the current contents of DVD\n");
        printf("\t5-Display the Indesis of the buffer\n");
        printf("\t6-Recently inserted value\n");
        printf("\t7-Exit\n");
        scanf ("%d", &ch);
        switch (ch){
            case 1:
                a = s[j];
                y = enqueue (a);
                
                    j++;
                break;
            case 2:
                c = dequeue ();
                DVD[n++] = c;
                a = s[j];
                y = enqueue (a);
                
                    j++;
                break;
            case 3:
                display ();
                break;
            case 4:
                display1 ();
                break;
            case 5:
                printf("\n The front and the rear indises are %d and %d.\n\n",front,rear);
                break;
            case 6:
                printf("\n The element which was burned recently is: %c\n\n",DVD[n-1]);
                break;
            case 7:
                break;
        }
    }
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You");
}

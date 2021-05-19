#include<stdio.h>

void Tower_of_Hanoi(int n, char from_rod, char to_rod, char aux_rod){
    if (n == 1) { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return;
    }
    Tower_of_Hanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    Tower_of_Hanoi(n-1, aux_rod, to_rod, from_rod); 
} 

void main(){ 
    int n;
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n");
    printf("Enter the value of n: ");
    scanf("%d",&n);
    Tower_of_Hanoi(n, 'A', 'C', 'B');
    printf("\tCompleted!!\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nThank You");
}

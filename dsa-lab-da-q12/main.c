#include<stdio.h>

struct Date{
    int year,month,day;
};

struct passp{
    int id;
    struct Date d;
};

int compare(const struct Date d1,const struct Date d2){
    if (d1.year < d2.year)
        return 1;
    if (d1.year == d2.year && d1.month < d2.month)
        return 1;
    if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
        return 1;
    return 0;
}

int main(){
    int i,j,min,n;
    struct passp t;
    struct passp p1[100],p2[100];
    printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("Please specify the number of records you would like to enter: ");
    scanf("%d",&n);
    printf("Enter records: \n");
    for(i=0;i<n;i++){
        printf("\n\tPassport ID: ");
        scanf("%d",&p1[i].id);
        printf("\tDate of renewal(DD MM YYYY): ");
        scanf("%d%d%d",&p1[i].d.day,&p1[i].d.month,&p1[i].d.year);
    }
    for(i=0;i<n;i++){
        p2[i]=p1[i];
    }
    for (i=1;i<n;i++){
        t=p1[i];
        j=i-1;
        while(p1[j].id > t.id && j>=0){
            p1[j+1]=p1[j];
            j--;
        }
        p1[j+1]=t;
    }
    printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("Records sorted based on Passport ID::\n");
    for (i=0;i<n;i++){
        printf("\n\tID: ");
        printf("%d",p1[i].id);
        printf("\t\t\t\tDate: ");
        printf("%d%s%d%s%d",p1[i].d.day,"-",p1[i].d.month,"-",p1[i].d.year);
    }
    printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    for (i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(compare(p2[j].d,p2[min].d)){
                min=j;
            }
        }
        t=p2[i];
        p2[i]=p2[min];
        p2[min]=t;
    }
    printf("Records sorted based on Date of Renewal::\n");
    for (i=0;i<n;i++){
        printf("\n\tDate: ");
        printf("%d%s%d%s%d",p2[i].d.day,"-",p2[i].d.month,"-",p2[i].d.year);
        printf("\t\t\t\tID: ");
        printf("%d",p2[i].id);
    }
    printf("\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
    printf("Thank You!!");
}



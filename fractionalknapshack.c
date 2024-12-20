#include<stdio.h>
int m,n;

struct object{
    int profit,weight;
    float avg;
}objects[100];

void insertion_sort(){
    struct object temp;
    int j;
    for(int i=1;i<n;i++){
        temp=objects[i];
        j=i-1;
        while(j>=0 && temp.avg>objects[j].avg){
            objects[j+1]=objects[j];
            j=j-1;
        }
        objects[j+1]=temp;
    }
}

void fractional(){
    int curr_weight=m;
    float total_profit=0;
    for(int i=0;i<n;i++){
        objects[i].avg=objects[i].profit/ (float) objects[i].weight;
    }
    insertion_sort();
    for(int i=0;i<n;i++){
        if(curr_weight>=objects[i].weight){
            total_profit=total_profit+objects[i].profit;
            curr_weight=curr_weight-objects[i].weight;
        }
        else{
            total_profit=total_profit+objects[i].avg*curr_weight;
            curr_weight=0;
            break;
        }
    }
    printf("\n total profit is:%f",total_profit);
}
int main(){
    printf("\n enter the no of objects:");
    scanf("%d",&n);
    printf("\n enter the weight limit:");
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        printf("\n\n enter the profit for object no %d:",i+1);
        scanf("%d",&objects[i].profit);
        printf("\n enter the weight for object no %d:",i+1);
        scanf("%d",&objects[i].weight);
    }
    fractional();
    return 0;
}
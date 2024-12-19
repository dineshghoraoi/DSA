#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int maxdead(int deadline[],int n){
    int max=deadline[0];
    for(int i=1;i<n;i++){
        if(deadline[i]>max){
            max=deadline[i];
        }
    }
    return max;
}

void sort(int profit[100],int deadline[100],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(profit[i]<=profit[j]){
                swap(&profit[i],&profit[j]);
                swap(&deadline[i],&deadline[j]);
            }
        }
    }
}

int main(){
    int n,j,profit[10],deadline[10],sequence[10],sum=0,max;
    printf("enter the no of jobs:");
    
    scanf("%d",&n);
    printf("\n enter the profit:");
    for(int i=0;i<n;i++){
        scanf("%d",&profit[i]);
    }
    
    
    
    printf("enter the deadlines of the jobs:");
    for(int i=0;i<n;i++){
        scanf("%d",&deadline[i]);
    }
    sort(profit,deadline,n);
    max=maxdead(deadline,n);
    
    


    for(int i=0;i<max;i++){
        sequence[i]=-1;
    }
    for(int i=0;i<n;i++){
        j=deadline[i];
        while(j>=0){
             
            if(sequence[j-1]==-1){
                sequence[j-1]=profit[i];
                break;
            }
            else{
                j=j-1;
            }
        }
    }
    for(int i=0;i<max;i++){
        sum=sum+sequence[i];
    }
    printf("\n total no profit is:%d",sum);

    return 0;
}
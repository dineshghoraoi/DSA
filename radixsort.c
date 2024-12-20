#include<stdio.h>

int max_find(int A[],int n){
    int max;
    max=A[0];
   for(int i=1;i<n;i++){
    if(A[i]>max){
        max=A[i];
   }
   }
   return max;
}


void counting_sort(int A[],int div,int n){
    int B[100],C[10]={0};
    for(int i=0;i<n;i++){
        C[(A[i]/div)%10]=C[(A[i]/div)%10]+1;
    }
    for(int i=1;i<10;i++){
       C[i]=C[i]+C[i-1];
    }
    for(int i=n-1;i>=0;i--){
        B[C[(A[i]/div)%10]-1]=A[i];
        C[(A[i]/div)%10]=C[(A[i]/div)%10]-1;
    }
    for(int i=0;i<n;i++){
        A[i]=B[i];
    }
}
void radix_sort(int A[],int n){
    int max,div;
    max=max_find(A,n);
    div=1;
    while(max/div>0){
        counting_sort(A,div,n);
        div=div*10;
    }
}

int main(){
    int n,A[100];
    printf("\n enter the no of lements:");
    scanf("%d",&n);
    printf("\n enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d,",&A[i]);
    }
    radix_sort(A,n);
    printf("\n sorted elements are:");
    for(int i=0;i<n;i++){
        printf(" %d",A[i]);
    }
    return 0;
}
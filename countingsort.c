#include<stdio.h>
int max_find(int A[],int n){
  int max=A[1];
  for(int i=2;i<=n;i++){
    if(A[i]>max){
        max=A[i];
    }
  }
  return max;
}

void counting_sort(int A[],int n){
    int max,B[20],C[20];
    max=max_find(A,n);
    for(int i=1;i<=max;i++){
        C[i]=0;
    }
    for(int i=1;i<=n;i++){
        C[A[i]]=C[A[i]]+1;
    }
    for(int i=2;i<=max;i++){
       C[i]=C[i]+C[i-1];
    }
    for(int i=n;i>=1;i--){
        B[C[A[i]]]=A[i];
        C[A[i]]=C[A[i]]-1;
    }
    printf("\nSorted elements are:");
    for(int i=1;i<=n;i++)
    {
       printf(" %d",B[i]);
    }

   
}
int main(){
    int n,A[20];
    printf("\n enter the no of elements:");
    scanf("%d",&n);
    printf("\n enter the elements of array:");
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    counting_sort(A,n);
    return 0;
}
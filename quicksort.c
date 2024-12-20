#include<stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[100],int low,int high){
    int pivot=arr[high];

    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quick_sort(int arr[100],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quick_sort(arr,pi+1,high);
        quick_sort(arr,low,pi-1);
    }
}
int main(){
    int size,arr[100];
    printf("\n enter the size of array:");
    scanf("%d",&size);
    printf("\n enter the elements of array:");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    quick_sort(arr,0,size-1);
   
    printf("\n sorted array is :\n");
    for(int i=0;i<size;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}
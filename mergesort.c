#include<stdio.h>
void mergesort(int *arr,int *leftarray,int ls,int *rightarray,int rs)
{
    int i=0,j=0,k=0;
    while(i<ls && j<rs)
    {
        if(leftarray[i]<=rightarray[j])
        {
            arr[k]=leftarray[i];
            i++;
        }
        else
        {
            arr[k]=rightarray[j];
            j++;
        }
        k++;
    }
    while(i<ls)
    {
        arr[k]=leftarray[i];
        i++;
        k++;
    }
    while(j<rs)
    {
        arr[k]=rightarray[j];
        j++;
        k++;
    }
}
void merge(int arr[],int n)
{
    if(n<2)
    return;
    int ls=n/2;
    int rs=n-ls;
    int leftarray[ls],rightarray[rs];
    for(int i=0;i<ls;i++)
    {
        leftarray[i]=arr[i];
    }
    for(int i=ls;i<n;i++)
    {
        rightarray[i-ls]=arr[i];
    }
    merge(leftarray,ls);
    merge(rightarray,rs);
    mergesort(arr,leftarray,ls,rightarray,rs);
}
int main()
{
    int n,arr[100];
    printf("\n enter the size of array:");
    scanf("%d",&n);
    printf("\n enter the elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d \n",arr[i]);
    }
    return 0;
}
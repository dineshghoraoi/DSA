#include<stdio.h>
int arr[100];
void swap(int*a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(n,largest);
    }
}
void heapsort(int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(i,0);
    }
}
int main()
{
    int n;
    printf("\n enter the size of array:");
    scanf("%d",&n);
    printf("\n enter the element \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("before sorting element are \n");
    for(int i=0;i<n;i++)
    {
       printf("%d \n",arr[i]);
    }
    heapsort(n);
    printf("after sorting element are \n");
    for(int i=0;i<n;i++)
    {
        printf("%d \n",arr[i]);
    }
    return 0;
}
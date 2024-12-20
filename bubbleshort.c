#include<stdio.h>
int main()
{
    int n,i,j,temp,arr[100],a;
    printf("\n enter the size of array: ");
    scanf("%d",&n);
    printf("enter the elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        a=0;
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                a=1;
            }
        }
        if(a==0)
        {
          break;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
}
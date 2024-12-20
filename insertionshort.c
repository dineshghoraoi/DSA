#include<stdio.h>
int main()
{
    int n,a[100],i,j,t;
    printf("enter the ize of array:");
    scanf("%d",&n);
    printf("enter the elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(a[j-1]>a[j])
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d \n",a[i]);
    }
    return 0;
}
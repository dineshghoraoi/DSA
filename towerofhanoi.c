#include<stdio.h>
void move(int n,char source,char dest,char helper);
int count=0;
int main()
{
    int n;
    printf("\n enter the no of rings:");
    scanf("%d",&n);
    move(n,'A','B','C');
    printf("\n \n total step=%d",count);
    return 0;
}
void move(int n,char source,char dest,char helper)
{
    if(n==1)
    {
        printf("move to %c to %c",source,dest);
        count++;
    }
    else
    {
        move(n-1,source,helper,dest);
        move(1,source,dest,helper);
        move(n-1,helper,dest,source);
    }
}
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int item)
{
    if(top==SIZE-1)
    {
        printf("\n stack is overflow ");
    }
    else
    {
        stack[++top]=item;
        printf("ITEM INSERTED \n %d",item);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack is underflow \n");
    }
    else
    {
        int item=stack[top--];
        printf("item deleted \n %d",item);
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty \n");
    }
    else
    {
    printf("stack elements \n");
    for(int i=0;i<=top;i++)
    {
        printf("%d \n",stack[i]);
    }
    printf("\n");
    }
}
int main()
{
    int choice,item;
    printf("1.push 2.pop 3.display 4.exit ");
    while(1)
    {
       printf("enter the choice:");
       scanf("%d \n",&choice);
       switch(choice)
       {
        case 1:printf("\n enter the value to push: ");
               scanf("%d",&item);
               push(item);
               break;
        case 2:pop();
               break;
        case 3:display();
               break;
        case 4:printf("exit \n");
        default:printf("indefind variable \n");              
       }
    }
    return 0;
}
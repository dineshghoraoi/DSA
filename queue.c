#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};struct node *front;
void insert()
{
    int item;
    if(front==NULL)
    {
        struct node *ptr;
        int item;
        ptr=(struct node*)malloc(sizeof(struct node*));
        printf("\nEnter the element you want to insert:");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=NULL;
        front=ptr;
        printf("\n %d inserted ",item);
    }
    else
    {
        int item;
        struct node *ptr,*rear;
        printf("\nenter the element :");
        scanf("%d",&item);
        rear=front;
        while(rear->next!=NULL)
        {
            rear=rear->next;
        }
        ptr->data=item;
        ptr->next=NULL;
        rear->next=ptr;
        rear=ptr;
        printf("\n %d inserted ",item);
    }
    
    printf("\n %d inserted ",item);
}
void delete()
{
    int item;
    struct node *ptr;
    if(front==NULL)
    {
        printf("\nUNDERFLOW!!");
    }else{
        item=front->data;
        ptr=front;
        front->next=front;
        free(ptr);
        printf("%d deleted",item);
    }
}
void display()
{
    struct node *ptr;
    if(front==NULL)
    {
        printf("Queue is empty.");
    }else{
        ptr=front;
        printf("Elements of queue are:");
        while(ptr->next!=NULL)
        {
            printf(" %d",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main()
{
    int choice;
    printf("1.insert 2.delete 3.display 4.exit");
    while(1)
    {
        printf("\n enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:printf("exit! \n");
                   break;
            defualt:printf("invalid choice \n");  
                    break;                          
        }
    
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
void insert_begining();
void insert_last();
void insert_random();
void delete_begining();
void delete_last();
void delete_random();
void reverse();
void search();
void display();
struct node
{
    int data;
    struct node*next;
};struct node*head;
int main()
{
    int choice;
    printf("1.insert begining \n 2.insert last \n 3.insert random \n 4.delete begining \n 5.delete last \n 6.delete random \n 7.reverse \n 8.search \n 9.display \n");
    while(choice!=10)
    {
        printf("enter the choice \n:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_begining();
                   break;
            case 2:insert_last();
                   break;
            case 3:insert_random();
                   break;
            case 4:delete_begining();
                   break;
            case 5:delete_last();
                   break;
            case 6:delete_random();
                   break;
            case 7:reverse();
                   break;
            case 8:search();
                   break;
            case 9:display();
                   break;
            case 10:printf("EXIT!");
                    break;
            default:printf("invalid choice !!");
        }
    }
    return 0;
}
void insert_begining()
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
    int item;
    if(ptr==NULL)
    {
        printf("OVERFLOW \n");
    }
    else
    {
        printf("\n enter the elements:");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("ITEM INSERTED \n",item);
    }
}
void insert_last()
{
    struct node*ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node*));
    int item;
    if(ptr==NULL)
    {
        printf("OVERFLOW \n");
    }
    else
    {
        printf("enter the elements\n:");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
            printf("\n ITEM INSERTED ",item);
        }
         else
         {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        printf("ITEM INSERTED \n",item);
         }
    }
}
void insert_random()
{
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node*));
    int item,loc;
    if(ptr==NULL)
    {
        printf("OVERFLOW \n");
    }
    else
    {
        printf("enter the elements \n");
        scanf("%d",&item);
        ptr->data=item;
        printf("enter the location \n");
        scanf("%d",&loc);
        temp=head;
        for(int i=1;i<loc;i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\n ITEM CAN NOT INSERTED");
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("ITEM INSERTED \n",item);
    }
}
void delete_begining()
{
    struct node*ptr;
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("item is deleted from begining \n");
    }
}
void delete_last()
{
    struct node*ptr,*temp;
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\n node are deleted ");
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        free(ptr);
        printf("item deleted from the last \n");
    }
}
void delete_random()
{
    struct node*ptr,*temp;
    int i,loc;
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
      printf("enter the loc \n");
      scanf("%d",&loc);
      ptr=head;
      for(i=1;i<loc;i++)
      {
        temp=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
        {
            printf("item can not deleted \n");
            return;
        }
      }
      temp->next=ptr->next;
      free(ptr);
      printf("list is deleted \n",loc);
    }
}
void reverse()
{
    struct node*curr,*prv,*temp;
    curr=head;
    prv=NULL;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prv;
        prv=curr;
        curr=temp;
    }
    head=prv;
}
void search()
{
    struct node*ptr;
    int item,i,flag=0;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\n list is empty ");
    }
    else
    {
        printf("enter the searching item \n");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
           if(ptr->data=item)
           {
             printf("\n found the searching location %d",i+1);
             flag=0;
           }
           else
           {
            flag=1;
           }
           i++;
           ptr=ptr->next;
        }
        if(flag=1)
        {
            printf("item is not found \n");
        }
    }
}
void display()
{
    struct node*ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
        printf("\n elements are:");
        while(ptr!=NULL)
        {
           printf("%d \n",ptr->data);
           ptr=ptr->next;
        }
    }
}
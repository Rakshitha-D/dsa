#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head=NULL;

void insertbegin()
{
    int item;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        printf("\nEnter the data to be inserted: ");
        scanf("%d",&item);
        newnode->prev=NULL;
        newnode->data=item;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
        }
    }
}

void insertend()
{
    int item;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        printf("\nEnter data to be entered: ");
        scanf("%d",&item);
        newnode->prev=NULL;
        newnode->data=item;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            struct node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
    }
}

void insertposition(int pos)
{
    int item;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        printf("\nEnter data to be inserted: ");
        scanf("%d",&item);
        newnode->prev=NULL;
        newnode->data=item;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            struct node *temp;
            temp=head;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
                if(temp==NULL)
                {
                    printf("\nNode can not be inserted");
                }
            }
            newnode->next=temp->next;
            temp->next->prev=newnode;
            newnode->prev=temp;
            temp->next=newnode;
        }
    }
}

void deletebegin()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nNode deleted");
    }
    else
    {
        struct node* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        printf("\nNode deleted at the beginning");
    }
}

void deleteend()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nNode deleted");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}

void deleteposition(int pos)
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nNode deleted");
    }
    else
    {
        struct node* temp=head;
        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp->prev->next=NULL;
            free(temp);
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}

void searching(int item)
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        int i=1,flag=1;
        struct node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==item)
            {
                printf("\nThe data is present at position %d",i);
                flag=0;
                break;
            }
            temp=temp->next;
            i++;
            break;
        }
        if(flag==1)
        {
            printf("\nData not found");
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main()
{
    int choice,pos,item;
    while(1)
    {
    printf("\n1.insertbegin\n2.insertend\n3.insertposition\n4.deletebegin\n5.deleteend\n6.deleteposition\n7.Searching\n8.Display\n9.exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insertbegin();
        break;
        case 2:
        insertend();
        break;
        case 3:
        printf("\nEnter position to insert node");
        scanf("%d",&pos);
        insertposition(pos);
        break;
        case 4:
        deletebegin();
        break;
        case 5:
        deleteend();
        break;
        case 6:
        printf("\nEnter position of node to delete");
        scanf("%d",&pos);
        deleteposition(pos);
        break;
        case 7:
        printf("\nEnter the data to be searched");
        scanf("%d",&item);
        searching(item);
        break;
        case 8:
        display();
        break;
        case 9:
        exit(0);
        default:
        printf("\nInvalid choice");
    }
    }
    return 0;
}


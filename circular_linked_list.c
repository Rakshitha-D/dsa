#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head=NULL;

void insertbegin()
{
    int item;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&item);
        newnode->data=item;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=newnode;
        }
        else
        {
            struct node *temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
            head=newnode;
            printf("\nNode inserted at the beginning\n");
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
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&item);
        newnode->data=item;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=newnode;
        }
        else
        {
            struct node *temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
            printf("\nNode inserted at the end\n");
        }
    }
}

void insertposition(int pos)
{
    int item;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        printf("\nEnter the value to be inserted");
        scanf("%d",&item);
        newnode->data=item;
        if(head==NULL)
        {
            printf("\nCan't insert at position as list is empty");
        }
        else
        {
            struct node *temp,*prev;
            temp=head;
            for(int i=1;i<pos;i++)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=newnode;
            newnode->next=temp;
        }
    }
}

void deletebegin()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==head)
    {
        free(head);
        head=NULL;
        printf("\nNode deleted\n");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        free(head);
        head=temp->next;
        printf("\nNode is deleted\n");
    }
}

void deleteend()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==head)
    {
        free(head);
        head=NULL;
        printf("\nNode is deleted\n");
    }
    else
    {
        struct node *temp,*prev;
        temp=head;
        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
        free(temp);
        printf("\nNode is deleted\n");
    }
}

void deleteinfo(int value)
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else 
    {
        struct node *temp,*prev;
        temp=head;
        while(temp->next!=head && temp->data!=value)
        {
            prev=temp;
            temp=temp->next;
        }
        
        if (temp->data != value) {
            printf("\nNode with value %d not found", value);
            return;
        }
        if(temp==head)
        {
            struct node *last=head;
            while(last->next!=head)
            {
                last=last->next;
            }
            head=head->next;
            last->next=head;
            free(temp);
            printf("\nNode deleted");
        }
        else
        {
            prev->next=temp->next;
            free(temp);
            printf("\nNode deleted");
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=head)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->",temp->data);
    }
}

int main()
{
    int choice,pos,value;
    while(1)
    {
        printf("\n1.Insertbegin\n2.insertend\n3.insertposition\n4.deletebegin\n5.deleteend\n6.deleteinfo\n7.Display\n8.exit");
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
            printf("\nEnter the position to insert a node: ");
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
            printf("\nEnter the value of node to be deleted: ");
            scanf("%d",&value);
            deleteinfo(value);
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);
            default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head=NULL;

void insertEnd(){
    
    int item;
    
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
        
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed\n");
    }
    printf("Enter data to be entered: ");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;
          
    if(head==NULL){
        head=newnode;
    } 
    else
    {
        struct node* current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
    }
    
}

void insertBegin(){
    int item;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed\n");
    }
    
    printf("\nEnter data to be entered: ");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;
    
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node* current=head;
        newnode->next=head;
        head=newnode;
    }
    
}

void insertposition(int pos){
    int item;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed\n");
    }
    
    printf("\nEnter data to be inserted: ");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;
    
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *prev,*temp;
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

void deleteBegin()
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        printf("\nNode is deleted\n");
    }
    else{
        struct node* temp=head;
        head=temp->next;
        free(temp);
        printf("\nNode deleted from begining\n");
    }
}

void deleteEnd()
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nNode Deleted\n");
    }
    else
    {
        struct node* current=head;
        struct node* prev=NULL;
        while(current->next!=NULL)
        {
            prev=current;
            current=current->next;
        }
        free(current);
        prev->next=NULL;
    }
}

void deleteposition(int pos)
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nNode deleted\n");
    }
    else
    {
        struct node *prev,*temp;
        temp=head;
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
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
                printf("\nThe data is found at position %d",i);
                flag=0;
            }
            temp=temp->next;
            i++;
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
        struct node* current=head;
        while(current->next!=NULL)
        {
            printf("%d->",current->data);
            current=current->next;
        }
        printf("%d",current->data);
    }
}

void freememory()
{
    struct node* current=head;
    while(current->next!=NULL)
    {
        struct node* temp=current;
        current=current->next;
        free(temp);
    }
}

int main()
{
    int choice,pos,item;
    while(1)
    {
        printf("\n1.insertBegin\n2.insertEnd\n3.insertposition\n4.deleteBegin\n5.deleteEnd\n6.deleteposition\n7.Display\n8.Searching\n9.Free Memory\n10.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertBegin();
            break;
            case 2:
            insertEnd();
            break;
            case 3:
            printf("\nEnter the position to insert new node: ");
            scanf("%d",&pos);
            insertposition(pos);
            break;
            case 4:
            deleteBegin();
            break;
            case 5:
            deleteEnd();
            break;
            case 6:
            printf("\nEnter the position of node to delete: ");
            scanf("%d",&pos);
            deleteposition(pos);
            break;
            case 7:
            display();
            break;
            case 8:
            printf("\nEnter the item to be searched");
            scanf("%d",&item);
            searching(item);
            break;
            case 9:
            freememory();
            break;
            case 10:
            exit(0);
            default:
            printf("invalid choice\n");
        }
    }
    
    return 0;
}

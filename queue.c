#include <stdio.h>
#include <stdlib.h>
#define size 5

int queue[size],f=-1,r=-1,item;

void insert()
{
    if(r==size-1)
    {
        printf("\nQueue is full");
    }
    else{
        printf("\nEnter data to be insereted: ");
        scanf("%d",&item);
        if(f==-1&&r==-1)
        {
            f=r=0;
        }
        else
        {
            r=r+1;
        }
        queue[r]=item;
        printf("\nValue inserted\n");
    }
}


void delete()
{
    if(f==-1||f>r)
    {
        printf("\nQueue is empty");
    }
    else
    {
        item=queue[f];
        if(f==r)
        {
            f=r=-1;
        }
        else
        {
            f=f+1;
        }
        printf("\nValue deleted");
    }
}

void display()
{
    if(r==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nvalues of queue are\n");
        for(int i=f;i<=r;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.insert\n2.delete\n3.display\n4.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}


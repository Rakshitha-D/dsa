#include <stdio.h>
#include <stdlib.h>
#define size 5
int stack[size],top=-1,n,value;

int IsFull(){
    if(top==size-1)
    printf("The stack is Full");
    else 
    return 0;
}

int IsEmpty()
{
    if(top==-1)
    printf("The stack is empty");
    else 
    return 0;
}

void push(int value)
{
    if(!IsFull())
    {
        ++top;
        stack[top]=value;
    }
}

void pop(){
    if(!IsEmpty())
    {
        top--;
    }
    
}

void peek(){
    if(!IsEmpty())
    {
        printf("The top element is %d",stack[top]);
    }
    
}

void display(){
    if(!IsEmpty())
    {
        printf("The items in the stack are: ");
        for(int i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
    }
}

int main()
{
    while(1)
    {
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            push(value);
        break;
        
        case 2:
            pop();
        break;
        case 3:
            peek();
        break;
        case 4:
            display();
        break;
        case 5:
            exit(0);
        break;
        default:
            printf("Invalid choice\n");
        
    }
    }

    return 0;
}



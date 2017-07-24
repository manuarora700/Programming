#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef struct _stack
{
    int stk[MAXSIZE];
    int top;
}
stack;

stack s;

void push(void);
int pop(void);
void display(void);

int main()
{
    int choice;
    int option = 1;
    s.top = -1;
    printf("STACK OPERATIONS\n");
    while(option)
    {
        printf("\n-------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Enter a valid option\n");
        }
        fflush (stdin);
        printf("\nDo you want to continue? (Type 0 for yes and 1 for no.)\n");
        scanf("%d", &option);
        }
        return 0;
}

// function definitions

void push(void)
{
    int num;
    if(s.top == (MAXSIZE - 1))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        printf("Enter the element to be pushed: ");
        scanf("%d", &num);
        
        s.top = s.top + 1;
        s.stk[s.top] = num;
        
        printf("Number successfully pushed to the stack\n");
    }
    return;
}

int pop(void)
{
    int num;
    if(s.top == -1)
    {
        printf("Stack is empty already bruh!\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf("Popped element is = %d", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return (num);
}

// display() the stack.

void display(void)
{
    int i;
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("\nStatus of the stack is \n");
        
        for(i = s.top; i >=0; i--)
        {
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}
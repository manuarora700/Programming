/* Stack operations using array and integer value
3 functions in total:
    a. push();
    b. pop();
    c. display();
*/

#include<stdio.h>
#include<stdlib.h>

// maximum size of the stack
#define MAXSIZE 5


// structure of the stack
typedef struct _stack
{
    // array containing stack value
    int stk[MAXSIZE];
    // takes care of the top of the stack
    int top;
}
stack;

stack s;

// function declarations
void push(void);
int pop(void);
void display(void);

int main()
{
    int choice;
    int option = 1;
    // top set to -1 for further operations
    s.top = -1;
    printf("STACK OPERATIONS\n");
    // loop to ask the user for operations over and over again.
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
    
    // if the top element is 1 less than the max size then the stack is full.
    if(s.top == (MAXSIZE - 1))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        printf("Enter the element to be pushed: ");
        scanf("%d", &num);
        
        // adds 1 index to the top position so that the next element comes on top
        s.top = s.top + 1;
        // saves the new value(input) on the array at index s.top
        s.stk[s.top] = num;
        
        printf("Number successfully pushed to the stack\n");
    }
    return;
}

int pop(void)
{
    int num;
    
    // if the top value is -1 then stack is already empty.
    if(s.top == -1)
    {
        printf("Stack is empty already bruh!\n");
        return (s.top);
    }
    else
    {
        // sets num value to s.stk top value so that the next push value can simply overwrite this current value.
        num = s.stk[s.top];
        printf("Popped element is = %d", s.stk[s.top]);
        
        // decrements the top indicating the one less position can be overwritten.
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
        // iterates over the s.stk array to print out values from first to last in the form of a stack.
        for(i = s.top; i >=0; i--)
        {
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}
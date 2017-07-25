#include<stdio.h>
#include<stdlib.h>
// struct is not necessary in queues.

// function declarations.
void enqueue(void);
void dequeue(void);
void display(void);

#define MAX 50

// queue requirements. array, front and rear.
int queue_array[MAX];
int front = -1;
int rear = -1;

int main()
{
    int choice;
    char ans = 'Y';
    // loops until the user exits.
    while(ans == 'Y' || ans == 'y')
    {
        printf("\n----------Queue operations-------------\n");
        printf("1. Insert into the queue (enqueue())\n");
        printf("2. Remove element from the queue (dequeue())\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("\n----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Enter a valid choice\n");
                break;
            
        }// end of switch
        printf("\nDO YOU WANT TO CONTINUE? (Hit y/n)\n");
        scanf(" %c", &ans);
    }// end of while
}// end of main

void enqueue(void)
{
    
    int add_item;
    // if rear is at the extreme end then no more element can be added into the queue.
    if(rear == MAX - 1)
        printf("\n Queue overflow!\n");
    else
    {
        //if queue is initially empty.
        if(front == -1)
        {
            // set front to 0th position
            front = 0;
        }
        printf("Enter the number to be inserted: ");
        scanf("%d", &add_item);
        
        //sets rear to rear++
        rear = rear + 1;
        // adds the number into the queue array.
        queue_array[rear] = add_item;
        printf("ELEMENT SUCCESSFULLY INSERTED\n");
    }
}// end of enqueue();

void dequeue(void)
{
    // if the queue is empty
    if(front == -1 || front > rear)
    {
        printf("Queue underflow\n");
        return;
    }
    else
    {
        printf("Element deleted from the queue is %d\n", queue_array[front]);
        // shifts front to +1 position ignoring the element to be deleted. We pretend that its deleted.
        front = front + 1;
    }
} // end of dequeue();

void display(void)
{
    int i;
    
    if(front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        
        // to display the queue we start fron the front and iterate up till the end.
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
} // end of display()

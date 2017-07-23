#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
sllnode;

sllnode* create(int);
void insert_node_first();
void insert_node_last();
void insert_node_position();
void sorted_ascending();
void delete_position();
void search();
void update_value();
void display();
void rev_display(sllnode *);

//typedef struct node sllnode;

sllnode *newnode;
sllnode *ptr;
sllnode *prev;
sllnode *temp;
sllnode *first = NULL;
sllnode *last = NULL;

int main()
{
    int choice;
    char ans = 'Y';
    
    while(ans =='Y' || ans == 'y')
    {
        printf("\n---------------------\n");
        printf("Welcome to linked list program\n");
        printf("\n---------------------\n");
        
        printf("\n 1. Insert node at first");
        printf("\n 2. Insert node at last");
        printf("\n 3. Insert node at a position");
        printf("\n 4. Sort linked list in ascending order");
        printf("\n 5. Delete element at a position in linked list");
        printf("\n 6. Update value of a node");
        printf("\n 7. Search element in the linked list");
        printf("\n 8. Display the entire linked list");
        printf("\n 9. Display list from end using recursion");
        printf("\n 0. Exit out of the program");
        
        printf("\n\n ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Inserting node at the first\n");
                insert_node_first();
                break;
            case 2:
                printf("Inserting node at the last\n");
                insert_node_last();
                break;
            case 3: 
                printf("Inserting node at the position\n");
                insert_node_position();
                break;
            case 4:
                printf("Sorting array in ascending order\n");
                sorted_ascending();
                break;
            case 5:
                printf("Deleting array at the mentioned position\n");
                delete_position();
                break;
            case 6:
                printf("Updating the node value at the mentioned position\n");
                update_value();
                break;
            case 7:
                printf("Searching value in the linked list\n");
                search();
                break;
            case 8:
                printf("Display the linked list from the beginning\n");
                display();
                break;
            case 9:
                printf("Displaying the list from end using recursion\n");
                rev_display(first);
                break;
            case 10:
                printf("Exiting from the linked list!\n");
                return 0;
                break;
            default:
                printf("ERROR! INVALID CHOICE\n");
                break;
        }
        
        printf("\nDo you want to continue? (Y/N)");
        scanf(" %c", &ans);
    }
    return 0;
}

// create()
sllnode* create(int val)
{
    newnode = (sllnode *)malloc(sizeof(sllnode));
    
    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }
    else
    {
        newnode->value =val;
        newnode->next = NULL;
        return newnode;
    }
}

// insert_node_first()

void insert_node_first()
{
    int val;
    printf("Enter value to be inserted into the node: ");
    scanf("%d", &val);
    
    newnode = create(val);
    if(first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        temp = first;
        first = newnode;
        first->next = temp;
    }
    printf("\n----INSERTED-------\n");
}

// insert_node_last()
void insert_node_last()
{
    int val;
    
    printf("Enter number to be inserted into the node: ");
    scanf("%d", &val);
    
    newnode = create(val);
    if(first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
    printf("\n-----INSERTED------\n");
}

//insert_node_position()

void insert_node_position()
{
    int pos, val, count = 0, i;
    printf("Enter the value to be inserted into the node: ");
    scanf("%d", &val);
    
    newnode = create(val);
    
    printf("\nEnter the position at which the element is to be inserted: ");
    scanf("%d", &pos);
    
    ptr = first;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
        count++;
    }
    
    if(pos == 1)
    {
        if (first == last && first == NULL)
        {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        }
        else
        {
            temp = first;
            first = newnode;
            first->next = temp;
        }
        printf("\nInserted");
    }
    else if(pos > 1 && pos <= count)
    {
        ptr = first;
        for(i = 1; i < pos; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newnode;
        newnode->next = ptr;
        printf("\n=====INSERTED======\n");
    }
    else
    {
        printf("position os outta range!\n");
    }
}

// sorted_ascending()

void sorted_ascending()
{
    sllnode *nxt;
    int t;
 
    if (first == NULL)
    {
        printf("Empty list!\n");
        printf(":No elements to sort\n");
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            for (nxt = ptr->next;nxt != NULL;nxt = nxt->next)
            {
                if (ptr->value > nxt->value)
                {    
                    t = ptr->value;
                    ptr->value = nxt->value;
                    nxt->value = t;
                }
            }
        }
        printf("\n---Sorted List---\n");
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}

// delete_position()
void delete_position()
{
    int pos, count = 0, i;
    
    if(first == NULL)
    {
        printf("Empty list\n");
        printf("No node to delete\n");
    }
    else
    {
        printf("Enter the position to be deleted: ");
        scanf("%d", &pos);
        ptr = first;
        
        if(pos == 1)
        {
            first =ptr->next;
            printf("Element deleted\n");
        }
        else
        {
            while(ptr!=NULL)
            {
                ptr = ptr->next;
                count++;
            }
            if(pos > 0 && pos <= count)
            {
                ptr = first;
                for(i = 1; i < pos; i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                    
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range\n");
            }
            free(ptr);
            printf("Element deleted\n");
        }
    }
}

// update_value()

void update_value()
{
    int oldval, newval, flag = 0;
    
    if(first == NULL)
    {
        printf("Empty list\n");
        printf("No nodes in the list to update\n");
    }
    else
    {
        printf("Enter the value to be updated: ");
        scanf("%d", &oldval);
        printf("\nEnter the new value: ");
        scanf("%d", &newval);
        
        for(ptr = first; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->value == oldval)
            {
                ptr->value = newval;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("Updated successfully!\n");
        }
        else
        {
            printf("Updation failed! Value not found in the list\n");
        }
    }
}

// search()

void search()
{
    int flag = 0, key, pos = 0;
    
    if(first == NULL)
    {
        printf("LL does not exist\n");
        printf("Search aborted\n");
        
    }
    else
    {
        printf("Enter the value to be searched: ");
        scanf("%d", &key);
        
        for(ptr = first; ptr != NULL; ptr = ptr->next)
        {
            pos = pos + 1;
            if(ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("Element %d found at %d position\n", key, pos);
        }
        else
        {
            printf("Element %d not found in the list!\n", key);
        }
    }
}

// display()

void display()
{
    
    if(first == NULL)
    {
        printf("LL does not exist\n");
        printf("No nodes to display!\n");
    }
    else
    {
        for(ptr = first; ptr != NULL; ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}

// rev_display();

void rev_display(sllnode *ptr1)
{
    int val;
    if(ptr1 == NULL)
    {
        printf("LL does not exits\n");
        printf("No node to display!\n");
    }
    else
    {
        if(ptr1 != NULL)
        {
            val = ptr1->value;
            rev_display(ptr1->next);
            printf("%d\t", val);
        }
    }
}
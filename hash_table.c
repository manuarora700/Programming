#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int key, age;
    char name[100];
    struct node *next;
}
node;

typedef struct hash
{
    node *head;
    int count;
}
hash;

hash *hashTable = NULL;
int eleCount = 0;

// creating a node.

node *createNode(int key, char *name, int age)
{
    node *newnode;
    newnode =(node *) malloc(sizeof(node));
    newnode->key = key;
    newnode->age = age;
    strcpy(newnode->name,name);
    newnode->next = NULL;
    return newnode;
}

// inserting into hashtable

void insertToHash(int key, char *name, int age)
{
    int hashIndex = key % eleCount;
    node *newnode = createNode(key, name, age);
    
    //head of the list
    if(!hashTable[hashIndex].head)
    {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    //adding newnode to the list.
    newnode->next = (hashTable[hashIndex].head);
    
    
    //update the head of the list
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

// deletion from hash table
void deleteFromHash(int key)
{
    //find bucket using hashIndex
    int hashIndex = key % eleCount, flag = 0;
    node *temp, *myNode;
    
    // get list head from current bucket
    myNode = hashTable[hashIndex].head;
    
    if(!myNode)
    {
        printf("Given data is not present in the hash table.\n");
        return;
    }
    
    temp = myNode;
    
    while(myNode != NULL)
    {
        // delete the node with the given key!
        
        if(myNode->key == key)
        {
            flag = 1;
            if(myNode == hashTable[hashIndex].head)
            {
                hashTable[hashIndex].head =myNode->next;
            }
            else
            {
                temp->next = myNode->next;
            }
            hashTable[hashIndex].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
        
    }
    if(flag)
    {
        printf("Data successfully deleted from the hash table\n");
    }
    else
    {
        printf("Data is not present in the hash table!\n");
    }
    return;
}

// Search in hash table!

void searchInHash(int key)
{
    int hashIndex = key % eleCount, flag = 0;
    node *myNode;
    myNode = hashTable[hashIndex].head;
    
    if(!myNode)
    {
        printf("Search element unavailable in hash table\n");
        return;
    }
    
    while(myNode != NULL)
    {
        if(myNode->key == key)
        {
            printf("ID    :%d\n", myNode->key);
            printf("Name  :%s\n", myNode->name);
            printf("Age   :%d\n", myNode->age);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if(!flag)
    {
        printf("Search element unavailable in the list!\n");
    }
    
    return;
}

// display the hash table.
void display()
{
    node *myNode;
    int i;
    for(i = 0; i < eleCount; i++)
    {
        if(hashTable[i].count == 0)
            continue;
        
        printf("\nData at index %d in hash Table:\n", i);
        printf("ID       Name       Age     \n");
        printf("-------------------------------\n");
        
        while(myNode != NULL)
        {
            printf("%d", myNode->key);
            printf("%s", myNode->name);
            printf("%d\n", myNode->age);
            myNode = myNode->next;
        }
    }
    return;
}


// main()
int main()
{
    int n, ch, key, age;
    char ans ='Y';
    char name[100];
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    
    eleCount = n;
    
    // Create hashtable with n number of buckets.
    
    hashTable = (hash *) calloc(n, sizeof(hash));
    while(ans == 'Y' || ans == 'y')
    {
        printf("\n1. Insertion\t2. Deletion\n");
        printf("3. Searching\t4. Display\n5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        
        switch (ch) 
        {
        case 1:
            printf("Enter the key value:");
            scanf("%d", &key);
            getchar();
            printf("Name:");
            fgets(name, 100, stdin);
            name[strlen(name) - 1] = '\0';
            printf("Age:");
            scanf("%d", &age);
            /*inserting new node to hash table */
            insertToHash(key, name, age);
            break;
 
        case 2:
            printf("Enter the key to perform deletion:");
            scanf("%d", &key);
            /* delete node with "key" from hash table */
            deleteFromHash(key);
            break;
 
        case 3:
            printf("Enter the key to search:");
            scanf("%d", &key);
            searchInHash(key);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("U have entered wrong option!!\n");
            break;
        }
    printf("Do you want to continue? (Y/N)\n");
    scanf(" %c", &ans);
    
    }
    return 0;
}
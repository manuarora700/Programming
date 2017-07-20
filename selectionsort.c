#include<stdio.h>

int main()
{
    int array[100];
    int n, position;
    
    printf("Enter number of values || size of array: \n");
    scanf("%d", &n);
    
    
    printf("Enter values: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("Entered array is: \n");
    for(int i = 0; i < n; i++)
    {
        printf(" %d |", array[i]);
    }
    printf("\n");
    
    for(int i = 0; i < n-1; i++)
    {
        position = i;
        
        for(int j = i+1; j < n; j++)
        {
            if(array[position] > array[j])
            {
                position = j;
            }
        }
        
        if(position != i)
        {
            int swap = array[i];
            array[i] = array[position];
            array[position] = swap;
        }
    }
    
    printf("Sorted list is: \n");
    
    for(int i = 0; i < n; i++)
    {
        printf(" %d |", array[i]);
    }
    printf("\n");
}
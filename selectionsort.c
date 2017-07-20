#include<stdio.h>

int main()
{
    // Variables to hold array values, position variable to know to position of smallest element, n for the number of elements.
    int array[100];
    int n, position;
    
    printf("Enter number of values || size of array: \n");
    scanf("%d", &n);
    
    // Loops to let the user enter values one by one.
    printf("Enter values: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    // Shows the entered array in a graphical format.

    printf("Entered array is: \n");
    for(int i = 0; i < n; i++)
    {
        printf(" %d |", array[i]);
    }
    printf("\n");
    
    // for loop to iterate over the whole array
    for(int i = 0; i < n-1; i++)
    {
        // Sets the position to ith element.
        position = i;
        
        // for loop to check the smallest element in the array.
        // i+1 so that it checks the next UNSORTED array and not the left SORTED array.
        for(int j = i+1; j < n; j++)
        {
            // if jth element is the smallest then set position = jth element. Do it until the whole array is traversed.
            if(array[position] > array[j])
            {
                position = j;
            }
        }
        // if position != i then swap the ith and the (position)th element. Repeat till the end of array
        if(position != i)
        {
            int swap = array[i];
            array[i] = array[position];
            array[position] = swap;
        }
    }
    

    // Print in graphical array format
    printf("Sorted list is: \n");
    
    for(int i = 0; i < n; i++)
    {
        printf(" %d |", array[i]);
    }
    printf("\n");
}
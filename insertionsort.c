#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start;
    // Declaring variables and an array
    int n, d;
    int array[100];
    printf("Enter the number of elements: \n");
    
    scanf("%d", &n);
    // Getting values for the array
    
    printf("Enter the values to be sorted: \n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    //Printing array in array graphical form
    
    printf("You entered: \n");
    for(int i = 0; i < n; i++)
    {
        printf("| %d ", array[i]);
    }
    printf("|\n");
    
    //Actual code for insertion sort
    // For loop to iterate through the array once
    start = clock();
    for(int i = 1; i < n; i++)
    {
        // Setting first elemented to sorted || d = i;
        
        d = i;
        
        // Swaps the values only if array[d] < array[d-1] and then decrements the value of d
        while(d > 0 && array[d] < array[d-1])
        {
            int temp = array[d];
            array[d] = array[d-1];
            array[d-1] = temp;
            
            d--;
        }
    }
    start = clock() - start;
    double time_taken = ((double)start)/CLOCKS_PER_SEC; // in seconds
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("| %d ", array[i]);
    }
    printf("|\n");
    
    printf("%f is the time taken by insertionSort\n", time_taken);

}



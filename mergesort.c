#include<stdio.h>
#include<time.h>
// Declarations for both the functions to be used.
// Added time.h module to track time taken by mergesort

void merge(int array[], int l, int m, int r);
void merge_sort(int array[], int l, int r);

int main()
{
    clock_t start;
    int n;
    printf("Enter the number of elements: \n");
    
    scanf("%d", &n);
    // Getting values for the array
    int array[n];
    printf("Enter the values to be sorted: \n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    // Declaring variables and an array    //Printing array in array graphical form
    
    printf("You entered: \n");
    for(int i = 0; i < n; i++)
    {
        printf("| %d ", array[i]);
    }
    printf("|\n");
    
    //MERGESORT with clock starts
    start = clock();
    
    //actual function
    merge_sort(array, 0, n);
    
    //stops the clock
    start = clock() - start;
    
    //calculates the time in seconds
    double time_taken = ((double)start)/CLOCKS_PER_SEC; // in seconds
    
    //prints array in sorted format
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("| %d ", array[i]);
    }
    printf("|\n");
    
    // Displays time taken
    printf("merge_sort() took %f seconds to execute \n", time_taken);
    return 0;
}


void merge(int array[], int l, int m, int r)
{
    // Creates i, j, and k variables. i = left subarray pointer, r = right subarray pointer, k = to hold the values and push into array.
    
    int i, j, k;
    
    //size of left subarray
    int n1 = m - l + 1;
    //size of right subarray
    int n2 = r - m;
    
    //creating two empty arrays to fill in the values for left and right sub arrays
    int L[n1], R[n2];
    
    //filling left sub array
    for(i = 0; i < n1; i++)
    {
        L[i] = array[l+i];
    }
    
    //filling right subarray
    for(j = 0; j < n2; j++)
    {
        R[j] = array[m+1+j];
    }
    
    //resetting pointers to 0th position and k = left most position i.e. 0
    i = 0;
    j = 0;
    k = l;
    
    // works i i < size of left subarray and j < size of right subarray
    while(i < n1 && j < n2)
    {
        
        // if left value is smaller than right then push the left element into the main array and increment i to the next value
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        
        //else do the same with right and increment j to the next value
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    //pushes remaining values into the array if there are any left.
    while(i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int l, int r)
{
    
    //Checks if left subarray is lesser then the right. proceeds only if l < r. 
    //if l is not less than r then the if condition is not satisfied and the control jumps to the caller function
    //which is the previous merge_sort() call. This basically means that the leftmost sub array (i.e. a single element) is there
    //so the control goes to the next line and performs merge_sort() on the right subarray and so on...
    
    if(l < r)
    {
        
        //Takes the middle value keeping in mind the condition for l overflow
        int m = l + (r-l)/2;
        
        //sorts the left subarray
        
        merge_sort(array, l, m);
        
        //sorts the right subarray
        merge_sort(array, m + 1, r);
        
        //merges the left and the right subarray.
        
        merge(array, l, m, r);
    }
}


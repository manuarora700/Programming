#include<stdio.h>
#include<time.h>

//function declaration of linear search and bubble sort

void bubble_sort(int [], int);
int binary_search(int array[], int l, int r, int target);
int main()
{
     
    
    //input for the values of array.
    int n, target;
    printf("Enter number of elements\n");
    scanf("%d,", &n);
    
    int array[n];
    
    printf("Enter values for the array:\n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("Enter the element to be searched\n");
    scanf("%d", &target);
    
    // SORTING
    // 
    bubble_sort(array, n); // Sorts the elements to prepare them for binary search.
    
    // Prints sorted list.
    printf("Sorted list is: \n");
    
    for(int l = 0; l < n; l++)
    {
        printf("%d |", array[l]);
    }
    printf("\n");
        
        
    // Binary search function with input as array, leftmost index, rightmost index and the element to find.
    int result = binary_search(array, 0, n, target);
    
    //if search returns - 1 then element is not found
    if(result == -1)
    {
        printf("element not found!\n");
    }
    //else it prints the index at which the element is present
    else
    {
        printf("Element found at index %d\n", result);
    }
    
}

// Program for bubble_sort
void bubble_sort(int array[], int n)
{
    for(int j = 0; j < n; j++)
    {
        
        // for loop to check two adjacent elements in the array
        for(int k = 0; k < n-j-1; k++)
        {
            //if left is greater than right then swap.
            if(array[k] > array[k+1])
            {
                // 3 lines of code to swap.
                int temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
            }
        }
    }
}
int binary_search(int array[], int l, int r, int target)
{
    // Always checks if the leftmost index is smaller than the rightmost index. the only case l > r is when the element is not present in the array.
    if(l <= r)
    {
        // sets the middle value and checks the condition for overflow.
        int mid = l + (r-l)/2;
        
        //if middle value is the target element then return middle value
        if(array[mid] == target)
            return mid;
        
        // if middle value is greater than the element to be searched then apply binary_search on left sub array.
        if(array[mid] > target)
            return binary_search(array, l, mid-1, target);
        
        // If not the left then apply binary_search on the right sub array.
        return binary_search(array, mid+1, r, target);
        }
    
    // We reach here if and only if r > l which is the case when the element is not present in the array. hence we return 0 and apply if condition in main().
    return -1;
}


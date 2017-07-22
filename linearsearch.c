#include<stdio.h>
#include<time.h>
//function declaration of linear search
void linear_search(int array[], int n, int search);
int main()
{
    clock_t t;  //For time 
    
    //input for the values of array.
    int n, search;
    printf("Enter number of elements\n");
    scanf("%d,", &n);
    
    int array[n];
    
    printf("Enter values for the array:\n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("Enter the element to be searched\n");
    scanf("%d", &search);
    
    
    t = clock();    //time starts
    linear_search(array, n, search); //actual code for linear search
    t = clock() - t; //time stops
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
    printf("time taken by linear search =  %f\n", time_taken);
}

void linear_search(int array[], int n, int search)
{
    int flag = 0; //flag set to 0. if the search is completed then the flag is set to 1 so that the if condition following it doesn't run.
    for(int i = 0; i < n; i++)
    {
        //if the element is present in the array then return it's index
        if(search == array[i])
        {
            printf("Element found at index %d\n", i);
            flag = 1; //set flag == 1
            break;
        }
    }
    //if the element is not present in the array then return false.
    if(flag == 0)
    {
        printf("Element not found in the array!\n");
    }
    
}
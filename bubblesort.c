#include<stdio.h>

int main(void)
{
    int n;

    // Array declared to store integers
    int array[1000];
    printf("Enter number of integers to be sorted\n");
    scanf("%d", &n);

    printf("Enter numbers: \n");
    
    // for loop to push values into the array.
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // For loop to print entered values in graphical array representation
    for(int j = 0; j < n; j++)
    {
    printf("%d | ", array[j]);
    }

    printf("\n");

    // for loop to iterate over the complete array
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
    printf("Sorted list is: \n");


    // for loop to print array in graphical form.
    for(int l = 0; l < n; l++)
    {
        printf("%d |", array[l]);
    }
    printf("\n");

    //Dafuq
}

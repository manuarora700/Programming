#include<stdio.h>

int main()
{
    int n, d;
    int array[100];
    printf("Enter the number of elements: \n");
    
    scanf("%d", &n);
    
    printf("Enter the values to be sorted: \n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("You entered: \n");
    for(int i = 0; i < n; i++)
    {
        printf("| %d ", array[i]);
    }
    printf("|\n");
    
    for(int i = 1; i < n; i++)
    {
        d = i;
        while(d > 0 && array[d] < array[d-1])
        {
            int temp = array[d];
            array[d] = array[d-1];
            array[d-1] = temp;
            
            d--;
        }
    }
    
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("| %d ", array[i]);
    }
    printf("|\n");
}
//Testing 1 2 3
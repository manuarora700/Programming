#include<stdio.h>

int main(void)
{
    //int swap_counter = -1;
    int n;
    
    int array[1000];
    printf("Enter number of integers to be sorted\n");
    scanf("%d", &n);
    
    printf("Enter numbers: \n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    for(int j = 0; j < n; j++)
    {
    printf("%d | ", array[j]);
    }
    
    printf("\n");
    
    for(int j = 0; j < n; j++)
    {
        for(int k = 0; k < n-j-1; k++)
        {
            if(array[k] > array[k+1])
            {
                int temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
            }
        }
    }
    printf("Sorted list is: \n");
    
    for(int l = 0; l < n; l++)
    {
        printf("%d |", array[l]);
    }
    printf("\n");
    
    
}
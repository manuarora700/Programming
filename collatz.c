#include<stdio.h>
int collatz(int n, int steps);
int main()
{
    int n;
    int steps =0;
    printf("Enter number: \n");
    scanf("%d", &n);
    
    int result = collatz(n, steps);
    
    printf("%d steps\n", result);
}

int collatz(int n, int steps)
{
    if(n == 1)
        return steps;
        
    else if(n%2 == 0)
    {
        steps++;
        return collatz(n/2, steps);
    }
    else
    {
        steps++;
        return collatz(3*n + 1, steps);
    }
    
}
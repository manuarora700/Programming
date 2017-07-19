#include<stdio.h>
//Program to swap two integers
void swap(int *c,int *d);
int main()
{
  int a, b;
  printf("Enter 2 numbers");
  scanf("%d %d", &a, &b);
  
  swap(&a, &b);

  printf("swapping...\n");

  printf("a = %d, b = %d\n", a, b);
<<<<<<< HEAD


=======
>>>>>>> 3085911367932af4d40e0424a2976e8eeab9694f
}

void swap(int *c, int *d)
{
  int temp = *c;
  *c =*d;
  *d = temp;
}
#include<stdio.h>
//Program to swap two integers
int main()
{
  int a, b;
  printf("Enter 2 numbers");
  scanf("%d %d", &a, &b);

  int temp = a;
  a = b;
  b = temp;

  printf("swapping...\n");

  printf("a = %d, b = %d\n", a, b);


}

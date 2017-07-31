// right aligned pyramid in c.

#include<stdio.h>
#include<cs50.h>

int main() 
{
    int pyramid_height = 0;
    
    do{
        printf("Height: ");
        
        pyramid_height = get_int();
        
        if(pyramid_height == 0) {
            return 0;
        }
        
    }while(pyramid_height <1 || pyramid_height >23);
    
    //first loop to iterate over the rows
    
    for(int i = 0; i <pyramid_height; i++)
    {
        for(int j = 0; j < pyramid_height - i - 1; j++)
        {
            printf("%s", " ");
        }
        
        for(int k = 0; k < i + 2; k++)
        {
            
            printf("#");
        }
        
        printf("\n");
        
    }
    return 0;
}
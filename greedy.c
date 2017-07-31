#include<stdio.h>
#include<cs50.h>
#include<math.h>
#define QUARTER 25;
#define DIME 10;
#define NICKLE 5;


int main(void)
{
    float given_amnt = 0;
    int cent_amnt = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickle_count = 0;
    int leftover = 0;
    int coin_count = 0;
    
    do {
        printf("Enter the amount in dollars: ");
        given_amnt = get_float();
    } while(given_amnt <= 0);
    
    //Dollars(given_amnt) to cents conversion using typecasting
    
    cent_amnt = (int)round(given_amnt * 100);
    
    // Number of quarter coins
    quarter_count = cent_amnt/QUARTER;
    leftover = cent_amnt % QUARTER;
    
    // Number of dimes
    
    dime_count = leftover/DIME;
    leftover = leftover % DIME;
    
    // Nickle count
    
    nickle_count = leftover / NICKLE;
    leftover = leftover % NICKLE;
    
    //ALL THE LEFTOVERS ARE NOW PENNIES BECAUSE ANYTHING SMALLER THAN NICKLES ARE PENNIES.
    
    coin_count = quarter_count + dime_count + nickle_count + leftover;
    
    printf("%i\n", coin_count);
    
    
    
    
}

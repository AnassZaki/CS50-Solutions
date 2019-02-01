#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int coins;
    do
    {
        coins = get_int("Amount: \n")
    }
    while(coins < 0);
    
}
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollar = 0;
    do
    {
        dollar = get_float("Amount: ");
    } while (dollar < 0);
    int coins = round(dollar * 100);
    int divisor[4] = {25, 10, 5, 1};
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        count += coins / divisor[i];
        coins = coins % divisor[i];
    }
    printf("%i\n", count);
}
#include <stdio.h>
#include <cs50.h>
#include <math.h>

// function that counts a number's digits
int count_digits(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

// function for the power
long long power(int base, int exponent)
{
    long long result = 1;
    while (exponent != 0)
    {
        result *= base;
        exponent = exponent - 1;
    }
    return result;
}

int main(void)
{
    long long credit = get_long("Your Credit Card Number: ");
    int credit_length = count_digits(credit);
    int checksum = 0;
    
    // loops over every second digit of the credit card number.
    // card_number = 4256 1234 0085 1299
    //           k =            .54 3210
    for (int k = 1; k < credit_length; k += 2) // 1 3 5 7
    {
        // get the digit at position k and multiply by 2
        int digit_k_2 = ((credit / power(10, k)) % 10) * 2;
        checksum += (digit_k_2 < 10) ? digit_k_2 : digit_k_2 - 9;
    }
    
    // sums every other digits
    for (int k = 0; k < credit_length; k += 2)
    {
        checksum += (credit / power(10, k)) % 10;
    }
    
    // Get the invalid case out first
    if (checksum % 10 != 0) 
    {
        printf("Invalid!\n");
        return 0;
    }
    
    int first_2_digits = credit / power(10, credit_length - 2);
    int first_digit = credit / power(10, credit_length - 1);
    
    if (credit_length == 15 && (first_2_digits == 34 || first_2_digits == 37))
    {
        printf("Amex !\n");
    }
    else if (credit_length == 16 && (first_2_digits >= 51 && first_2_digits <= 55))
    {
        printf("MasterCard !\n");
    }
    else if ((credit_length == 13 || credit_length == 16) && first_digit == 4)
    {
        printf("Visa !\n");
    }
}






#include <cs50.h>
#include <stdio.h>

//main function
int main(void)
{
    int height = 0;
    //prompt user for a number
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height >= 23);
    {
        //builds the pyramids
        for (int i = 0; i < height; i++)
        {
            for (int j = i + 1; j < height; j++)
            {
                printf(" ");
            }
            for (int k = 0; k <= i; k++)
            {
                printf("#");
            }
            printf("  ");
            for (int k = 0; k <= i; k++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}

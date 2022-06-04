#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    // Do-while loop here till user adds a value thats not less than 1
    do
    {
        // We take height of pyramid as input here
        n = get_int("Please Enter height of pyramid: ");
    }
    while (n < 1 || n >= 9);

    // Loop to create the pyramid
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
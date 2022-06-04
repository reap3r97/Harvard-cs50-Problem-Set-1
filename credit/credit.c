#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get credit card number
    long ccNum = get_long("Number: ");

    // Counting card number length
    int i = 0;
    long n = ccNum;

    while (n > 0)
    {
        n = n / 10;
        i++;
    }

     // Check if length of card is valid
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculating checksum
    int firstSum = 0;
    int secondSum = 0;
    long x = ccNum;
    int total = 0;
    int firstMod;
    int secondMod;
    int double1;
    int double2;

    do
    {
        // Remove last digit and add to sum1
        firstMod = x % 10;
        x = x / 10;
        firstSum = firstSum + firstMod;

        // Remove second last digit
        secondMod = x % 10;
        x = x / 10;

        // Double second last digit and add digits to sum2
        secondMod = secondMod * 2;
        double1 = secondMod % 10;
        double2 = secondMod / 10;
        secondSum = secondSum + double1 + double2;
    }
    while (x > 0);

    total = firstSum + secondSum;

    // Checking Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get starting digits
    long start = ccNum;

    do
    {
        start = start / 10;
    }
    while (start > 100);

     // Next check starting digits for card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
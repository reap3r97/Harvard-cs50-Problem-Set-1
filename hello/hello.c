#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // We take name as input from user
    string name = get_string("Enter your name: ");

    printf("hello, %s\n", name);
}
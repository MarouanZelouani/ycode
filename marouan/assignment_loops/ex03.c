#include <stdio.h>

int main ()
{
    int number;
    int i;
    int v = 0;

    printf("Enter a number :");
    scanf("%d", &number);

    i = 2;
    while (i <= number / 2)
    {
        if (number % i == 0)
            v = 1;
        i++;
    }

    if (v == 0)
        printf("number is prime");
    else 
        printf("number is not prime");
    return 0;
}
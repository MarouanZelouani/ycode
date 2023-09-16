#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number)
{
    int i;
    int v = 0;

    i = 2;
    while (i <= number / 2)
    {
        if (number % i == 0)
            v = 1;
        i++;
    }

    if (v == 0)
        return true;
    else 
        return false;
}

int main ()
{
    int n;
    printf ("enter a number\n");
    scanf("%d", &n);
    if (is_prime(n))
        printf ("%d is prime\n", n);
    else 
        printf ("%d is not prime\n", n);
}


#include <stdio.h>
#include <stdbool.h>

bool is_parfait(int number)
{
    int s = 0;
    int i;

    i = 1;
    while (i <= number / 2)
    {
        if (number % i == 0)
            s = s + i;
        i++;
    }

    if (s == number)
        return true;
    else 
        return false;
}

int main ()
{
    int n;
    printf ("enter a number :", n);
    scanf("%d", &n);
    if (is_parfait(n))
        printf ("%d is parfait\n", n);
    else 
        printf ("%d is not parfait\n", n);
}
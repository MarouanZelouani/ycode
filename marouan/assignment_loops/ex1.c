#include <stdio.h>

int main ()
{
    int number;
    int i;

    i = 1;
    printf ("enter a number :");
    scanf ("%d", &number);

    while (i <= 10)
    {
        printf("%d * %d = %d\n", number, i, number * i);
        i++;
    }
}
#include <stdio.h>

int pgcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return pgcd(b , a%b);
}

int main ()
{
    int a, b, result;

    printf("enter a :");
    scanf("%d", &a);

    printf("enter b :");
    scanf("%d", &b);

    result = pgcd(a,b);
    printf("PGCD(%d, %d) = %d\n", a, b, result);
}
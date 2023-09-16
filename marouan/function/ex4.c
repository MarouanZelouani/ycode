#include <stdio.h>

int Max_4(int a, int b, int c, int d)
{
    int max = 0;

    if (a > max)
        max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;

    return max;
}

int main ()
{
    int a, b, c, d;

    printf("enter a :");
    scanf("%d", &a);

    printf("enter b :");
    scanf("%d", &b);

    printf("enter c :");
    scanf("%d", &c);

    printf("enter d :");
    scanf("%d", &d);

    printf("max = %d\n", Max_4(a, b, c, d));
}
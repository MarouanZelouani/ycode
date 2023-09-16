#include <stdio.h>

int Permuter (int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main ()
{
    int a, b;

    printf("enter a :");
    scanf("%d", &a);

    printf("enter b :");
    scanf("%d", &b);

    Permuter(&a, &b);

    printf("a = %d\nb = %d", a, b);
    
}
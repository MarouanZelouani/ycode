#include <stdio.h>

int main ()
{
    int size;
    int i;

    printf("enter size :");
    scanf("%d", &size);

    int tab[size];

    i = 0;
    while (i < size)
    {
        printf("enter a number :");
        scanf("%d", &tab[i]);
        i++;
    }

    printf("enter a number to insert in the end of the table :");
    scanf("%d", &tab[size]);

    i = 0;
    while (i < size + 1) printf("%d\n", tab[i++]);
}
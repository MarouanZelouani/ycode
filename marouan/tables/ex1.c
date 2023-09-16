#include <stdio.h>

int main()
{
    int tab[5];
    int i = 0;
    int s = 0;

    while (i < 5)
    {
        printf("enter a number :");
        scanf("%d", &tab[i++]);
    }

    i = 0;
    while (i < 5) s += tab[i++];

    i = 0;
    while (i < 5) printf("%d\n", tab[i++]);
    printf("somme = %d", s);
}
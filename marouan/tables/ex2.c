#include <stdio.h>

int main ()
{
    int tab [] = {1, 4, 9, 2, 5};
    int i = 0;
    int s = 0;
    int p = 1;
    int m;

    while (i < 5) s += tab[i++];
    i = 0;
    while (i < 5) p *= tab[i++];
    m = s / 5;

    printf("somme = %d\n", s);
    printf("produit = %d\n", p);
    printf("moyenne = %d\n", m);
}
#include <stdio.h>

int main ()
{
    int i;
    int j;
    int tmp;
    int tab[] = {1, 12, 8, 3, 7};
    int size = 5;

    for (i = 1; j <= size - 1; j++)
    {
        j = i;
        while (j > 0 && tab[i-1] < tab[i])
        {
            tmp = tab[i-1];
            tab[i-1] = tab[i];
            tab[i] = tmp;
            j--;
        }
    }
}

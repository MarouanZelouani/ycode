#include <stdio.h>

int main ()
{
    int i;
    int j;
    int tmp;
    int tab[] = {1, 8, 6, 5, 12, 0, 88};
    int size = 7;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < size) printf("%d\n", tab[i++]);
}
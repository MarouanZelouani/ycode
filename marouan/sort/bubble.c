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
        j = 0;
        while (j < size - i - 1)
        {
            if (tab[j] > tab[j+1])
            {
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp; 
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < size) printf("%d\n", tab[i++]);
}
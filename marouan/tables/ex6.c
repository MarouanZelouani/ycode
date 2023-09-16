#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int size;
    int i = 0;
    int count = 0;

    printf("enter size :");
    scanf("%d", &size);

    int tab[size];

    while (i < size) 
        tab[i++] = (rand() %  26) + 'A';
    tab[i] = '\0';
    i = 0;
    while (tab[i]) printf("%c\n", tab[i++]);
    i = 0;
    while (i < size)
    {
        if((int)tab[i+1] - (int)tab[i] == 1)
            count++;
        i++;
    }
    printf("=====> %d", count);
}
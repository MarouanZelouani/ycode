#include <stdio.h>

int main ()
{
    int size;
    int i;
    int option;

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

    printf("choose your option !!:\n");
    printf("input 1 (insert in the beginning?)\n");
    printf("input 1 (insert in the middle?)\n");
    printf("input 2 (insert in the end?)\n");
    scanf("%d", &option);

    if (option == 1)
    {
        i = size;
        while (i < 0)
        {
            tab[i] = tab[i-1];
            i--;
        }
        printf("enter a number to insert in the end of the table :");
        scanf("%d", &tab[0]);
    }
    else if (option == 2)
    {
        i = size;
        while (i > size / 2)
        {
            tab[i] = tab[i - 1];
            i--;
        }
        printf("enter a number to insert in the end of the table :");
        scanf("%d", &tab[(int)(size/2)]);
    }
    else if (option == 3)
    {
        printf("enter a number to insert in the end of the table :");
        scanf("%d", &tab[size]);
    }

    i = 0;
    while (i < size + 1) printf("%d\n", tab[i++]);
}
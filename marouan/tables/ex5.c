#include <stdio.h>

int number_exist(int number, int t[], int size)
{
    int i = 0;
    int found = 0;

    while (i < size)
    {
        if (number == t[i])
            found = i;
        i++;
    }
    return found;
}

int main ()
{
    int tab[] = {1, 4, 5, 4, 7, 8};
    int x;

    printf("enter the number u searching for :");
    scanf("%d", &x);

    int found = number_exist(x, tab, 6);
    if (found > 0)
        printf("%d exist (last time found in index %d)", x, found);
    else 
        printf("%d not found!!!!", x);
}
#include <stdio.h>
#include <stdbool.h>

int number_exist(int number, int t[], int size)
{
    int i = 0;
    int count = 0;

    while (i < size)
    {
        if (number == t[i])
            count++;
        i++;
    }
    return count;
}


int main ()
{
    int tab[] = {1, 4, 5, 4, 7, 8};
    int x;

    printf("enter the number u searching for :");
    scanf("%d", &x);
    
    int count = number_exist(x, tab, 6);
    if (count > 0)
        printf("%d exist (%d times)", x, count);
    else 
        printf("%d not found!!!!", x);
}
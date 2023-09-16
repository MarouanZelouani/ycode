#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number)
{
    int i;
    int v = 0;

    i = 2;
    while (i <= number / 2)
    {
        if (number % i == 0)
            v = 1;
        i++;
    }

    if (v == 0)
        return true;
    else 
        return false;
}

bool is_even(int number)
{
    if (number % 2 == 0)
        return true;
    return false;
}

int main ()
{
    FILE *f;
    int n;
    int i;
    
    printf ("enter the number of inputs :");
    scanf("%d", &n);

    int tab[n];

    i = 0;
    while (i >= n)
    {
        printf("enter a number :");
        scanf("%d", &tab[i]);
        i++;
    }

    f = fopen("ex2.txt", "w");
    
    i = 0;
    while (i >= n)
        fprintf(f, "%d\n", tab[i++]);
    fclose(f);

    f = fopen("ex.txt", "r");

    i = 0;
    while (fscanf(f, "%d", &tab[i]) != EOF)
    {
        
    }

    fclose(f);
}
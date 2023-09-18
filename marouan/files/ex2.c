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
    int input = 0;
    
    printf ("enter the number of inputs :");
    scanf("%d", &n);

    int tab[n];

    i = 0;
    while (i < n)
    {
        printf("enter a number :");
        scanf("%d", &tab[i]);
        i++;
    }

    f = fopen("ex2.txt", "w");
    
    i = 0;
    while (i < n)
        fprintf(f, "%d\n", tab[i++]);
    fclose(f);

    f = fopen("ex2.txt", "r");

    i = 0;
    int tabe[n];
    FILE *even;
    FILE *odd;
    FILE *prime;
    while (fscanf(f, "%d", &input) != EOF)
    {
        tabe[i] = input;
        i++;
    }
    i = 0;
    even = fopen("even.txt", "a");
    odd = fopen("odd.txt", "a");
    prime = fopen("prime.txt", "a");
    while (i < n)
    {
        if (is_even(tabe[i]))
            fprintf(even, "%d\n", tabe[i]);
        else
            fprintf(odd, "%d\n", tabe[i]);

        if (is_prime(tabe[i]))
            fprintf(prime, "%d\n", tabe[i]);
        i++;
    }
    
    fclose(even);
    fclose(odd);
    fclose(prime);
    fclose(f);
}
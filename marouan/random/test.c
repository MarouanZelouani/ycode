#include<stdio.h>
#include<stdlib.h>

void convert_to_binary(int number)
{
    int bin[100];
    int n = number;
    int i = 0;

    if (n == 0)
        printf("0");
    while (n > 0)
    {
        bin[i++] = n % 2;
        n /= 2;
    }
    i--;
    while (i >= 0)
        printf("%d", bin[i--]);
    printf("\n");
}

int main(int ac, char *av[])
{
    int num = atoi(av[1]);
    convert_to_binary(num);
}
#include <stdio.h>

int main()
{
    int row_number;
    int i;
    int j;

    i = 1;

    printf("row number = ");
    scanf("%d", &row_number);

    while (i <= row_number)
    {
        j = i;
        while (j < row_number)
        {
            printf(" ");
            j++;
        }
        j = 1;
        while (j <= (2*i-1))
        {
            printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
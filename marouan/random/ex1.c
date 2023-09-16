#include<stdio.h>

int main ()
{
    int row_number;
    int colmn_number;

    int i = 1;
    int j = 1; 

    printf("input number of rows :");
    scanf("%d", &row_number);

    printf("input number of colmns :");
    scanf("%d", &colmn_number);

    while (i <= row_number)
    {
        j = 1;
        while (j <= colmn_number)
        {
            printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
}
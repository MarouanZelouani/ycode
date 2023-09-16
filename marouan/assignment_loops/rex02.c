#include <stdio.h>

int main()
{
    int row_number = 4;
    int i;
    int j;
    int r = row_number;
    int b = row_number;

    i = 1;

    while (i <= row_number)
    {
        j = r;
        while (j < row_number)
        {
            printf(" ");
            j++;
        }
        j = 1;
        while (j <= (2*b-1))
        {
            printf("*");
            j++;
        }
        printf("\n");
        i++;
        r--;
        b--;
    }
    return 0;
}
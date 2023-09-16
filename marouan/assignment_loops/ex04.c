#include <stdio.h>

int main ()
{
    int s = 0;
    int number;
    int finish = 1;
    int max = 0;

    while (finish != 0)
    {
        printf("input a number (-1 to quit):");
        scanf("%d", &number);

        if (number == -1)
            finish = 0;
        else if (number < -1 || number > 100)
        {
            printf("invalid number!!!\ninput another number (0<number<100) :");
            scanf("%d", &number);
        }
        if (number % 10 == 0)
        {
            s+=number;
            if (number > max)
                max = number; 
        }      
    }
    printf("s = %d\n", s);
    printf("max = %d", max);
}
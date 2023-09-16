#include <stdio.h>

void q1 ()
{
    int number;
    int i;

    i = 1;
    printf ("enter a number :");
    scanf ("%d", &number);

    while (i <= 10)
    {
        printf("%d * %d = %d\n", number, i, number * i);
        i++;
    }
}

void q2 () 
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
}

void q3 ()
{
    int number;
    int i;
    int v = 0;

    printf("Enter a number :");
    scanf("%d", &number);

    i = 2;
    while (i <= number / 2)
    {
        if (number % i == 0)
            v = 1;
        i++;
    }

    if (v == 0)
        printf("number is prime");
    else 
        printf("number is not prime");
}

void q4 () 
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
    printf("max = %d\n", max);
}

void q5 ()
{
    int n;
    
    printf("enter a number :");
    scanf("%d", &n);

    while (n > 0)
    {
        printf("%d", n%10);
        n= n/10;
    }
    printf("\n");
}
void menu (int choice_number) 
{
    switch (choice_number) {
        case 1:
            q1();
            break;
 
        case 2:
            q2();
            break;
 
        case 3:
            q3();
            break;
            
        case 4:
            q4();
            break;

        case 5:
            q5();
            break;
    }
}

int print_menu (int error)
{
    int choice;

    if (error == -1)
        printf("invalid choice!!! try again :) .\n");
    printf("*----------------------------MENU-----------------------------*\n");
    printf("* Press 1 for multiblication table.                           *\n");
    printf("* Press 2 to draw a piramide whit stars.                      *\n");
    printf("* Press 3 for testing if a number is prime.                   *\n");
    printf("* Press 4 to get the sum and max of a serie of numbers.       *\n");
    printf("* Press 5 to print a number in revers.                        *\n");
    printf("* Press -1 to quit.                                           *\n");
    printf("*-------------------------------------------------------------*\n");
    printf("* Enter your choice:                                           \n");
    scanf("%d", &choice);
    printf("*-------------------------------------------------------------*\n");

    return choice;
}

int main ()
{
    int choice_number;
    int stop = 1;
    while (stop != -1)
    {
        choice_number = print_menu(1);
        if(choice_number >= 1 && choice_number <= 5)
            menu(choice_number);
        else if (choice_number == -1)
            stop = -1;
        else 
            choice_number = print_menu(-1);
    } 
}
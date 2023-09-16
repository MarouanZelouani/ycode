#include <stdio.h>

int Somme(int x, int y)
{
    return x + y;
}

int main()
{
    int x;
    int y;

    printf("enter a number :");
    scanf("%d", &x);

    printf("enter another number :");
    scanf("%d", &y);

    printf("x + y = %d\n", Somme(x, y));

}
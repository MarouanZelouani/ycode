#include<stdio.h>
#include<math.h>

int main ()
{
    int a, b, c;
    int s = 0;

    printf("a = ?\n");
    scanf("%d", &a);
    printf("b = ?\n");
    scanf("%d", &b);
    printf("c = ?\n");
    scanf("%d", &c);

    int d = pow(b, 2)-(4*a*c);
    if (d < 0)
    {
        printf("error!!!!!\n no solution.....");
        return 0;
    }
    else if (d == 0)
    {
        s = (b/(2*a)) * (-1);
        printf("a = %d b = %d c = %d\n", a, b, c);
        printf ("x = %d\n", s);
        return 0;
    }
    else if (d > 0)
    {
        s = (-b-sqrt(d))/(2*a);
        printf ("x1 = %d\n", s);
        s = (-b+sqrt(d))/(2*a);
        printf ("x2 = %d\n", s);
        return 0;
    }
}
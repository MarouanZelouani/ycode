#include<stdio.h>
#include<math.h>

void eq_solution(int a, int b, int c)
{
    float s = 0;
    int d = (b*b)-(4*a*c);
    printf("%d\n",d);
    if (d < 0)
    {
        printf("error!!!!!\n no solution.....");
        return ;
    }
    else if (d == 0)
    {
        s = (b/(2*a)) * (-1);
        if (s < 0)
           s *= -1;
        printf("a = %d b = %d c = %d\n", a, b, c);
        printf ("x1 = %f\n", sqrt(s));
        printf ("x2 = %f\n", -sqrt(s));
        return ;
    }
    else if (d > 0)
    {
        s = (-b-sqrt(d))/(2*a);
        if (s < 0)
           s *= -1;
        printf ("x1 = %f\n", sqrt(s));
        printf ("x2 = %f\n", -sqrt(s));
        s = (-b+sqrt(d))/(2*a);
        if (s < 0)
            s *= -1;
        printf ("x3 = %f\n", sqrt(s));
        printf ("x4 = %f\n", -sqrt(s));
        return ;
    }
}

int main ()
{
    int a, b, c;

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    eq_solution(a, b, c);
}
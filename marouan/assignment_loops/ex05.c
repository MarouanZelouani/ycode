#include <stdio.h>

int main()
{
    int n = 123456789;
   
    while (n > 0)
    {
        printf("%d", n%10);
        n= n/10;
    }
}
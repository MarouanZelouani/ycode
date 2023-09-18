#include <stdio.h>

int main ()
{
    int t1[] = {1, 2, 3};
    int t2[] = {4, 5, 6};
    
    int size_t1 = 3;
    int size_t2 = 3;
    int size_t3 = size_t1 + size_t2;
    
    int t3[size_t3];
    int i;
    int j = 0;

    i = 0;
    while (i < size_t1) {t3[i] = t1[i]; i++;};
    i = size_t1;
    while (i < size_t3) {
        t3[i] = t2[j]; 
        i++;
        j++;
    };

    i = 0;
    printf("t1 : ");
    while (i < size_t1) printf("%d ", t1[i++]);
    printf("\n");
    i = 0;
    printf("t2 : ");
    while (i < size_t2) printf("%d ", t2[i++]);
    printf("\n");
    i = 0;
    printf("t3 : ");
    while (i < size_t3) printf("%d ", t3[i++]);
}
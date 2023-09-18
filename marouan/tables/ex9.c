#include <stdio.h>

int main()
{
    int t[] = {1, 2, 3, 4, 5};
    int i;
    int element;
    int element_index = 0;
    int size = 5;

    printf("enter the element u wanna delete :");
    scanf("%d", &element);

    i = 0;
    while (i < size && element_index == 0)
    {
        if (t[i] == element)
        {
            element_index = i;
        }
        i++;
    }
    printf("index of element (%d) is : %d\n", element, element_index);

    i = element_index;
    while (i < size - 1) {t[i] = t[i+1]; i++;};
    
    size = size - 1;
    i = 0;
    while (i < size) printf("%d\n", t[i++]);
}
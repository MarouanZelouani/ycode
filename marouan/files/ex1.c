#include <stdio.h>

int main () 
{
    FILE *f;
    int i = 1;

    f = fopen("file.txt", "w");

    while (i <= 100){fprintf(f, "%d\n", i); i++;}
        
    fclose(f);

    f = fopen("file.txt", "r");
    int input = 0;

    while (fscanf(f, "%d", &input) != EOF)
        printf("%d\n", input);
    fclose(f);
}
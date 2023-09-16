#include <stdio.h>

int main ()
{
    char t[20];
    //int i = 0;

    printf("enter your name:");
    scanf("%s", t);
    //scanf("%[^\n]s", t);

   
    printf("%s", t);


    /*
    while (i < 100)
        t[i++] = i;
    FILE *f;
    f = fopen("marouan.txt", "w");
    i = 0;
    while (i < 100) 
        fprintf(f, "%d\n", t[i++]);
    fclose(f);
    */ 
}
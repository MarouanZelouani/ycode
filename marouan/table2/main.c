#include <stdio.h>
#include <string.h>

void add_student(char names[][50], int grades[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("enter name of the student :");
        scanf("%s", names[i]);
        //gets(names[i]);
        printf("enter student grade :");
        scanf("%d", &grades[i]);
        printf("-------------------------->\n");
        i++;
    }
}

void search_note_byname(char names[][50], int grades[], int size)
{
    char name[50];
    int i;
    int grade_index = 0;

    printf("enter the name of student :");
    scanf("%s", name);

    i = 0;
    while (i < size && grade_index == 0)
    {
        if(strcmp(name, names[i]) == 0)
            grade_index = i;
        i++;
    }

    printf("this the current grade of --> %s : %d\n", name, grades[grade_index]);
}

int somme (int size, int grades[])
{
    int s = 0;
    int i = 0;

    while (i < size)
    {
        s += grades[i];
        i++;
    }
    return s;
}

int moyenne(int size, int grades[])
{
    int s ;
    s = somme(size, grades) / size;
    return s;
}

void display_students(char names[][50], int grades[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("------> student %i :\n", i+1);
        printf("name : %s\n", names[i]);
        printf("grade : %d\n", grades[i]);
        printf("-------------------------->\n");
        i++;
    }
}

void modify_grade(char names[][50], int grades[], int size)
{
    int i;
    int updated_grade;
    int grade_index = 0;
    char name[50];

    printf("enter the name of student u wann update:");
    scanf("%s", name);

    i = 0;
    while (i < size && grade_index == 0)
    {
        if(strcmp(name, names[i]) == 0)
            grade_index = i;
        i++;
    }

    printf("this the current grade of --> %s : %d\n", name, grades[grade_index]);
    printf("enter the new value :");
    scanf("%d", &updated_grade);

    grades[grade_index] = updated_grade;
}

void cmp_to_moyenne (int grades[], int size, int moyenne)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (grades[i] == moyenne)
            printf("%d = moyenne\n", grades[i]);
        else if (grades[i] < moyenne)
            printf("%d < moyenne\n", grades[i]);
        else 
            printf("%d > moyenne\n", grades[i]);
        i++;
    }
}

int how_many_sup(int grades[], int size, int moyenne)
{
    int i;
    int count = 0;

    i = 0;
    while (i < size)
    {
        if (grades[i] > moyenne) 
            count++;
        i++;
    }
    return count;
}

void min_grade (int grades[], int size)
{
    int i;
    int min = grades[0];
    int index = 0;

    i = 0;
    while (i < size)
    {
        if (grades[i] < min)
        {
            min = grades[i];
            //index = i;
        }  
        i++;
    }

    i = 0;
    while (i < size && index == 0)
    {
        if(grades[i] == min)
            index = i;
        i++;
    }

    printf("min = %d in index = %d\n", min, index);
}

void max_grade (int grades[], int size)
{
    int i;
    int max = grades[0];
    int index = 0;

    i = 0;
    while (i < size)
    {
        if (grades[i] > max)
        {
            max = grades[i];
            //index = i;
        }  
        i++;
    }
    
    i = 0;
    while (i < size && index == 0)
    {
        if(grades[i] == max)
            index = i;
        i++;
    }

    printf("max = %d in index = %d\n", max, index);
}

int delete_student(char names[][50], int grades[], int size)
{
    int i;
    int index = 0;
    char name[50];
    int to_continue;
    int new_size = size;

    printf("enter name of the student u wanna delete :");
    scanf("%s", name);

    i = 0;
    while (i < size && index == 0)
    {
        if(strcmp(names[i], name) == 0)
            index = i;
        i++;
    }

    printf("u shure u want to delete --> %s --> grade : %d\n", name, grades[index]);
    printf("enter 1 to continue 0 to quite :");
    scanf("%d", &to_continue);

    if (to_continue = 1)
    {
        i = index;
        while (i < size - 1)
        {
            strcpy(names[i], names[i+1]);
            i++;
        }

        i = index;
        while (i < size - 1)
        {
            grades[i], grades[i+1];
            i++;
        }

        new_size = size - 1;
    }
    return new_size;
}

void sort_student(char names[][50], int grades[], int size)
{
    int i;
    int j;
    int tmp;
    char name_holder[50];

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (grades[i] > grades[j])
            {
                tmp = grades[i];
                grades[i] = grades[j];
                grades[j] = tmp;

                strcpy(name_holder, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], name_holder);
            }
            j++;
        }
        i++;
    }
}

int main ()
{
    int size;
    int error = 0;
    int print_error = 0;

    while (error == 0)
    {   
        if (print_error == 1)
            printf("enter another value > 0 and <20 !!!!!\n");
        printf("enter the number of student :");
        scanf("%d", &size);
        if ((size > 0) && (size <= 20))
        {
            error = 1;
            
        }
        else print_error = 1;
    }
    
    char names[size][50];
    int grades[size];

    add_student(names, grades, size);
    display_students(names, grades, size);
    //modify_grade(names, grades, size);
    //display_students(names, grades, size);
    //size = delete_student(names, grades, size);
    //display_students(names, grades, size);
    //sort_student(names, grades, size);
    //display_students(names, grades, size);
    //printf("moyenne : %d\n", moyenne(size, grades));
    //printf("-------------------------->\n");
    //cmp_to_moyenne(grades, size, moyenne(size, grades));
    //printf("-------------------------->\n");
    //int h = how_many_sup(grades, size, moyenne(size, grades));
    //printf("how manny grades is sup to moyenne : %d\n", h);
    //printf("-------------------------->\n");
    //min_grade(grades, size);
    //max_grade(grades, size);
}
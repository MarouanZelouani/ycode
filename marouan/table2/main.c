#include <stdio.h>
#include <string.h>

void add_student(char names[][50], float grades[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("enter name of the student :");
        scanf("%s", names[i]);
        //gets(names[i]);
        printf("enter student grade :");
        scanf("%f", &grades[i]);
        printf("-------------------------->\n");
        i++;
    }
}

void search_note_byname(char names[][50], float grades[], int size)
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
    if (grade_index == -1)
        printf("can not be found !!!!!!");
    else 
        printf("this the current grade of --> %s : %.2f\n", name, grades[grade_index]);
}

float somme (int size, float grades[])
{
    float s = 0;
    int i = 0;

    while (i < size)
    {
        s += grades[i];
        i++;
    }
    return s;
}

float moyenne(int size, float grades[])
{
    float s ;
    s = somme(size, grades) / size;
    return s;
}

void display_students(char names[][50], float grades[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("------> student %i :\n", i+1);
        printf("name : %s\n", names[i]);
        printf("grade : %.2f\n", grades[i]);
        printf("-------------------------->\n");
        i++;
    }
}

void modify_grade(char names[][50], float grades[], int size)
{
    int i;
    float updated_grade;
    int grade_index = -1;
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

    if (grade_index == -1)
        printf("can not be found !!!!!!");
    else
    {
        printf("this the current grade of --> %s : %.2f\n", name, grades[grade_index]);
        printf("enter the new value :");
        scanf("%f", &updated_grade);

        grades[grade_index] = updated_grade;
    }
}

void cmp_to_moyenne (float grades[], int size, float moyenne)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (grades[i] == moyenne)
            printf("%.2f = moyenne\n", grades[i]);
        else if (grades[i] < moyenne)
            printf("%.2f < moyenne\n", grades[i]);
        else 
            printf("%.2f > moyenne\n", grades[i]);
        i++;
    }
}

int how_many_sup(float grades[], int size, float moyenne)
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

void min_grade (float grades[], int size)
{
    int i;
    float min = grades[0];
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

    printf("min = %.2f in index = %d\n", min, index);
}

void max_grade (float grades[], int size)
{
    int i;
    float max = grades[0];
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

    printf("max = %.2f in index = %d\n", max, index);
}

int delete_student(char names[][50], float grades[], int size)
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

    printf("u shure u want to delete --> %s --> grade : %.2f\n", name, grades[index]);
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
            grades[i] = grades[i+1];
            i++;
        }

        new_size = size - 1;
    }
    return new_size;
}

void sort_student(char names[][50], float grades[], int size)
{
    int i;
    int j;
    float tmp;
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

int menu (int choice_number, char names[][50], float grades[], int size) 
{
    int new = size;
    int h;
    switch (choice_number) {
        case 1:
            display_students(names, grades, size);
            printf("---------------------------------------->\n");
            break;
        case 2:
            modify_grade(names, grades, size);
            break;
        case 3:
            new = delete_student(names, grades, size);
            break;
        case 4:
            sort_student(names, grades, size);
            break;
        case 5:
            printf("moyenne : %.2f\n", moyenne(size, grades));
            printf("--------------------------------------->\n");
            break;
        case 6:
            cmp_to_moyenne(grades, size, moyenne(size, grades));
            printf("---------------------------------------->\n");
            break;
        case 7:
            h = how_many_sup(grades, size, moyenne(size, grades));
            printf("how manny grades is sup to moyenne : %d\n", h);
            printf("----------------------------------------->\n");
            break;
        case 8:
            min_grade(grades, size);
            printf("---------------------------------------->\n");
            break;
        case 9:
            max_grade(grades, size);
            printf("---------------------------------------->\n");
            break;
        case 10:
            search_note_byname(names, grades, size);
            printf("---------------------------------------->\n");
            break;
    }
    return new;
}

int print_menu (int error)
{
    int choice;

    if (error == -1)
        printf("invalid choice!!! try again :) .\n");
    printf("*----------------------------MENU-----------------------------*\n");
    printf("* Press 1 to display student.                                 *\n");
    printf("* Press 2 to modify student grade.                            *\n");
    printf("* Press 3 to delete a student.                                *\n");
    printf("* Press 4 to sort students by there grade.                    *\n");
    printf("* Press 5 to calculate and display moyenne.                   *\n");
    printf("* Press 6 to compare grades to moyenne.                       *\n");
    printf("* Press 7 to calculate how many grades are sup to moyenne.    *\n");
    printf("* Press 8 to print min gade.                                  *\n");
    printf("* Press 9 to print max grade                                  *\n");
    printf("* Press 10 to search for grade by student.                    *\n");
    printf("* Press -1 to quit.                                           *\n");
    printf("*-------------------------------------------------------------*\n");
    printf("* Enter your choice:                                           \n");
    scanf("%d", &choice);
    printf("*-------------------------------------------------------------*\n");

    return choice;
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
    float grades[size];

    printf("-------------------------->\n");
    add_student(names, grades, size);

    /*
    modify_grade(names, grades, size);
    display_students(names, grades, size);
    size = delete_student(names, grades, size);
    display_students(names, grades, size);
    printf("-------------------------->\n");
    sort_student(names, grades, size);
    display_students(names, grades, size);
    printf("moyenne : %.2f\n", moyenne(size, grades));
    printf("-------------------------->\n");
    cmp_to_moyenne(grades, size, moyenne(size, grades));
    printf("-------------------------->\n");
    int h = how_many_sup(grades, size, moyenne(size, grades));
    printf("how manny grades is sup to moyenne : %d\n", h);
    printf("-------------------------->\n");
    min_grade(grades, size);
    printf("-------------------------->\n");
    max_grade(grades, size);
    */
    

    int choice_number;
    int stop = 1;
    while (stop != -1)
    {
        choice_number = print_menu(1);
        if(choice_number >= 1 && choice_number <= 10)
            size = menu(choice_number, names, grades, size);
        else if (choice_number == -1)
            stop = -1;
        else 
            choice_number = print_menu(-1);
    } 
}
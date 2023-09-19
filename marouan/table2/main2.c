#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void add_cars(char car_module[][50], char license_number[][50], float km[], bool status[], int size)
{
    int i;
    int s;

    i = 0;
    while (i < size)
    {
        printf("enter module of the car :");
        scanf("%s", car_module[i]);
        printf("enter license number of the car :");
        scanf("%s", license_number[i]);
        printf("enter kms of the car :");
        scanf("%f", &km[i]);
        printf("enter staus of the car (1 exist 0 not):");
        scanf("%d", &s);
        if (s == 1)
            status[i] = true;
        else 
            status[i] = false;
        printf("-------------------------->\n");
        i++;
    }
}

void display_cars(char car_module[][50], char license_number[][50], float km[], bool status[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("------> car %i :\n", i+1);
        printf("module : %s\n", car_module[i]);
        printf("licence number : %s\n", license_number[i]);
        printf("kms : %.2f km\n", km[i]);
        if (status[i])
            printf("car exist.\n");
        else 
            printf("car deos not exist.\n");
        printf("-------------------------->\n");
        i++;
    }
}

int search(char license_number[][50], int size, char licence_holder[])
{
    int i;
    int index = -1;

    i = 0;
    while (i < size && index == -1)
    {
        if (strcmp(licence_holder, license_number[i]) == 0)
        {
            index = i;
        }
        i++;
    }

    return index;
}

int change_status (char car_module[][50], char license_number[][50], float km[], bool status[], int size)
{
    char licence_holder[50];
    int index = 0;

    printf("enter the licence number i wanna change its status:");
    scanf("%s", licence_holder);

    index = search(license_number, size, licence_holder);

    if (index == -1)
        printf("error!!!");
    else 
    {
        if (status[index])
        {
            status[index] == false;
            printf("status changed !!");
        }
        else printf("erroe!!!!");
    }
}

void return_car(char car_module[][50], char license_number[][50], float km[], bool status[], int size)
{
    char licence_holder[50];
    int index = 0;
    int k;

    printf("enter the licence number i wanna return :");
    scanf("%s", licence_holder);

    index = search(license_number, size, licence_holder);

    if (index == -1)
        printf("error!!!");
    else 
    {
        printf("car : current kms ---> %.2f", km[index]);
        printf("enter the km :");
        scanf("%d", &k);

        km[index] = k;
        status[index] = true;
    }
}

void display_one_car(char licence[], char car_module[][50], char license_number[][50], float km[], bool status[], int size)
{
    int index = 0;

    index = search(license_number, size, licence);

    if (index == -1)
        printf("error!!!");
    else 
    {
        printf("------> car %i :\n", index);
        printf("module : %s\n", car_module[index]);
        printf("licence number : %s\n", license_number[index]);
        printf("kms : %.2f km\n", km[index]);
        if (status[index])
            printf("car exist.\n");
        else 
            printf("car deos not exist.\n");
        printf("-------------------------->\n");
    }
}

void test_status(char car_module[][50], char license_number[][50], float km[], bool status[], int size)
{
    int index = 0;
    char licence[50];

    printf("enter the licence of the car :");
    scanf("%s", licence);

    index = search(license_number, size, licence);

    if (index == -1)
        printf("error!!!");
    else 
    {
        if (status[index])
            display_one_car(license_number[index], car_module, license_number, km, status, size);
        else printf("error");
    }
}

void ques(char car_module[][50], char license_number[][50], float km[], bool status[], int size)
{
    int i;
    int total_number = 0;
    int number_exist = 0;
    int number_note_exist = 0;
    float km_moyenne = 0;

    i = 0;
    while (i < size)
    {
        total_number += 1;
        km_moyenne += km[i];
        i++;
    }

    km_moyenne = km_moyenne/total_number;

    i = 0;
    while (i < size)
    {
        if (status[i])
            number_exist += 1;
        else number_note_exist += 1;
        i++;
    }

    printf("total number : %d\n", total_number);
    printf("number of existing cars : %d\n", number_exist);
    printf("number of not existing cars : %d\n", number_note_exist);
    printf("km moyenne : %.2f\n", km_moyenne);
}

void menu (int choice_number, char car_module[][50], char license_number[][50], float km[], bool status[], int size) 
{
    switch (choice_number) {
        case 1:
            change_status(car_module, license_number, km, status, size);
            printf("---------------------------------------->\n");
            break;
        case 2:
            return_car(car_module, license_number, km, status, size);
            printf("--------------------------------------->\n");
            break;
        case 3:
            test_status(car_module, license_number, km, status, size);
            printf("--------------------------------------->\n");
            break;
        case 4:
            ques(car_module, license_number, km, status, size);
            printf("--------------------------------------->\n");
            break;
    }
}

int print_menu (int error)
{
    int choice;

    if (error == -1)
        printf("invalid choice!!! try again :) .\n");
    printf("*----------------------------MENU-----------------------------*\n");
    printf("* 1 Louer une voiture.                                        *\n");
    printf("* 2 Retour d'une voiture.                                     *\n");
    printf("* 3 Etat d'une voiture.                                       *\n");
    printf("* 4 Etat du parc de voitures.                                 *\n");
    //printf("* 5 Sauvegarder l’état du parc.                               *\n");
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

    printf("enter the number of cars :");
    scanf("%d", &size);

    char car_module[size][50];
    char license_number[size][50];
    float km[size];
    bool status[size];

    printf("------------------------------>\n");
    add_cars(car_module, license_number, km, status, size);

    int choice_number;
    int stop = 1;
    while (stop != -1)
    {
        choice_number = print_menu(1);
        if(choice_number >= 1 && choice_number <= 10)
            menu(choice_number, car_module, license_number, km, status, size);
        else if (choice_number == -1)
            stop = -1;
        else 
            choice_number = print_menu(-1);
    } 
}
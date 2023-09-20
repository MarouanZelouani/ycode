#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct date
{
    int day;
    int month;
    int year;
}Date;

typedef struct task
{
    int id;
    char title[50];
    char description[100];
    Date deadline;
    char status[50];
    Date date;
} task;

void freeTask(task* t) {
    if (t != NULL) {
        free(t);
    }
}

bool is_valid_date (int day, int month, int year)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    if (day < tm.tm_mday || month < tm.tm_mon+1 )
        if (year < tm.tm_year+1900)
            return false;
    return true;
}

void display_task(task t)
{
    printf("---------------------->\n");
    printf("id : %d\n", t.id);
    printf("title : %s\n", t.title);
    printf("description : %s\n", t.description);
    printf("deadline : %d-%d-%d\n", t.deadline.day, t.deadline.month, t.deadline.year);
    printf("status : %s\n", t.status);
    printf("Date : %d-%d-%d\n", t.date.day, t.date.month, t.date.year);
}

void display_tasks(task tasks[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        display_task(tasks[i]);
        i++;
    }
}

void add_task(task *tasks, int size)
{
    char status_holder;
    int error = 0;
    int print_error = 0;
    char temp;
    char temp1;

    tasks[size - 1].id = size;
    printf("title :");
    scanf("%c",&temp);
	fgets(tasks[size - 1].title, 50, stdin);
    tasks[size - 1].title[strcspn(tasks[size - 1].title, "\n")] = 0;
    printf("description :");
    scanf("%c",&temp1);
	fgets(tasks[size - 1].description, 100, stdin);
    tasks[size - 1].description[strcspn(tasks[size - 1].description, "\n")] = 0;

    while (error == 0)
    {   
        if (print_error == 1)
        {
            printf("error!!!!!\n");
            printf("invalid date ----> try again!!!!\n");
        }
        printf("Deadline :\n");
        printf("day :");
        scanf("%d", &tasks[size - 1].deadline.day);
        printf("month :");
        scanf("%d", &tasks[size - 1].deadline.month);
        printf("year :");
        scanf("%d", &tasks[size - 1].deadline.year);
        if (is_valid_date(tasks[size - 1].deadline.day, 
            tasks[size - 1].deadline.month, 
            tasks[size - 1].deadline.year))
        {
            error = 1;
        }
        else print_error = 1;
    }

    error = 0;
    print_error = 0;

    while (error == 0)
    {   
        if (print_error == 1)
        {
            printf("error!!!!!\n");
            printf("status ----> (todo , doing, done)\n");
        }   
        printf("status :");
        scanf("%s", tasks[size - 1].status);
        if (strcmp(tasks[size - 1].status, "todo") == 0 || 
            strcmp(tasks[size - 1].status, "doing") == 0 || 
            strcmp(tasks[size - 1].status, "done") == 0)
        {
            error = 1;
        }
        else print_error = 1;
    }

    error = 0;
    print_error = 0;

    printf("------------------------------->\n");

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    tasks[size - 1].date.day = tm.tm_mday;
    tasks[size - 1].date.month = tm.tm_mon+1;
    tasks[size - 1].date.year = tm.tm_year+1900;
}

void add_tasks(task *tasks, int size, int s, int flag)
{
    int i = 0;
    int error = 0;
    int print_error = 0;
    char temp;
    char temp1;

    if(flag == 1)
        i = 0;
    else if (flag > 1)
        i = size;
    printf("%d\n",i);
    while (i < s)
    {
        tasks[i].id = i + 1;
        printf("title :");
        scanf("%c",&temp);
	    fgets(tasks[i].title, 50, stdin);
        tasks[i].title[strcspn(tasks[i].title, "\n")] = 0;
        printf("description :");
        scanf("%c",&temp1);
	    fgets(tasks[i].description, 100, stdin);
        tasks[i].description[strcspn(tasks[i].description, "\n")] = 0;
        
        while (error == 0)
        {   
            if (print_error == 1)
            {
                printf("error!!!!!\n");
                printf("invalid date ----> try again!!!!\n");
            }
            printf("Deadline :\n");
            printf("day :");
            scanf("%d", &tasks[i].deadline.day);
            printf("month :");
            scanf("%d", &tasks[i].deadline.month);
            printf("year :");
            scanf("%d", &tasks[i].deadline.year);
            if (is_valid_date(tasks[i].deadline.day, 
                tasks[i].deadline.month, 
                tasks[i].deadline.year))
            {
                error = 1;
            }
            else print_error = 1;
        }

        error = 0;
        print_error = 0;
        
        while (error == 0)
        {   
            if (print_error == 1)
            {
                printf("error!!!!!\n");
                printf("status ----> (todo , doing, done)\n");
            }   
            printf("status :");
            scanf("%s", tasks[i].status);
            if (strcmp(tasks[i].status, "todo") == 0 || 
                strcmp(tasks[i].status, "doing") == 0 || 
                strcmp(tasks[i].status, "done") == 0)
            {
                error = 1;
            }
            else print_error = 1;
        }

        error = 0;
        print_error = 0;

        printf("---------------------------->\n");

        time_t t;
        t = time(NULL);
        struct tm tm = *localtime(&t);

        tasks[i].date.day = tm.tm_mday;
        tasks[i].date.month = tm.tm_mon+1;
        tasks[i].date.year = tm.tm_year+1900;
        i++;
    }
}

int print_menu (int error)
{
    int choice;

    if (error == -1)
        printf("invalid choice!!! try again :) .\n");
    printf("*----------------------------MENU-----------------------------*\n");
    printf("* Press 0 to add multible tasks.                              *\n");
    printf("* Press 1 to add one task.                                    *\n");
    printf("* Press 2 to disalay tasks.                                   *\n");
    printf("* Press -1 to quit.                                           *\n");
    printf("*-------------------------------------------------------------*\n");
    printf("* Enter your choice:                                           \n");
    scanf("%d", &choice);
    printf("*-------------------------------------------------------------*\n");

    return choice;
}

int main()
{
    int size = 0;
    int s = 0;
    int option;
    task* tasks = NULL;
    int stop = 0;
    int flag = 0;
    int error = 0;

    

    while (stop != -1)
    {

        //printf("enter option :");
        //scanf("%d", &option);

        option = print_menu(0);

        if (option == 0)
        {
            printf("enter size :");
            scanf("%d", &s);
            int size1 = size;
            size = size + s;

            if (flag > 0)
            {
                flag++;
                tasks = (task*)realloc(tasks, (size * sizeof(task)));
                if (tasks == NULL) {
                    printf("Memory allocation failed!!");
                    return 1;
                }
            }
            if (flag == 0)
            {
                flag++;
                tasks = (task*)malloc(size * sizeof(task));
                if (tasks == NULL) {
                    printf("Memory allocation failed");
                    return 1;
                }
            }
        
            printf("<-----------------add tasks---------------->\n");
            add_tasks(tasks, size1, size, flag);
        }
        if (option == 1)
        {
            size++;
            if (flag > 0)
            {
                flag++;
                tasks = (task*)realloc(tasks, (size * sizeof(task)));
                if (tasks == NULL) {
                    printf("Memory allocation failed!!");
                   return 1;
                }
            }
            if (flag == 0)
            {
                flag++;
                tasks = (task*)malloc(size * sizeof(task));
                if (tasks == NULL) {
                    printf("Memory allocation failed");
                    return 1;
                }
            }

            printf("<---------------add one task--------------->\n");
            add_task(tasks, size);
        }
        if (option == 2)
        {
            printf("<-------------display all tasks------------>\n");
            display_tasks(tasks, size);
        }
        if (option == -1)
            stop = -1;
    }

    free(tasks);
    printf("nice you make it :)\n");
}
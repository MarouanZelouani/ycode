#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
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
    int deadline;
    char status[50];
    Date date;
} task;

bool is_Emty(task t[], int size)
{
    bool isEmpty = true;
    int i;

    i = 0;
    while (i < size)
    {
        if (t[i].id != 0 || t[i].title[0] != '\0' || 
            t[i].description[0] != '\0' || t[i].deadline != 0 || 
            t[i].status[i] != '\0' || t[i].date.day != 0 ||
            t[i].date.month != 0 || t[i].date.year != 0) {
            isEmpty = false;
            break;
        }
        i++;
    }
    return !isEmpty;
}

void freeTask(task* t) {
    if (t != NULL) {
        free(t);
    }
}

void display_task(task t)
{
    printf("---------------------->\n");
    printf("id : %d\n", t.id);
    printf("title : %s\n", t.title);
    printf("description : %s\n", t.description);
    printf("deadline : %d\n", t.deadline);
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

void add_task(task *tasks, int *size)
{
    //(*size)++;
    /*
    if (!is_Emty(tasks, (*(size) - 1)))
    {
        printf("realoc\n");
        tasks = (task*)realloc(tasks, ((*size) * sizeof(task)));
        if (tasks == NULL) {
            printf("Memory allocation failed!!");
            return ;
        }
    }
    
    else 
    {
        tasks = (task*)malloc((*size) * sizeof(task));
        printf("malloc\n");
        if (tasks == NULL) {
            printf("Memory allocation failed!!");
            return ;
        }
    }
    */
    
        
    printf("id :");
    scanf("%d", &tasks[(*size) - 1].id);
    printf("title :");
    scanf("%s", tasks[(*size) - 1].title);
    printf("description :");
    scanf("%s", tasks[(*size) - 1].description);
    printf("deadline :");
    scanf("%d", &tasks[(*size) - 1].deadline);
    printf("status :");
    scanf("%s", tasks[(*size) - 1].status);
    printf("------------------------------->\n");

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    tasks[(*size) - 1].date.day = tm.tm_mday;
    tasks[(*size) - 1].date.month = tm.tm_mon+1;
    tasks[(*size) - 1].date.year = tm.tm_year+1900;
}

void add_tasks(task *tasks, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("id :");
        scanf("%d", &tasks[i].id);
        printf("title :");
        scanf("%s", tasks[i].title);
        printf("description :");
        scanf("%s", tasks[i].description);
        printf("deadline :");
        scanf("%d", &tasks[i].deadline);
        printf("status :");
        scanf("%s", tasks[i].status);
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

int main()
{
    int size = 0;
    int s;
    int option;
    task* tasks = NULL;
    int stop = 0;
    int flag = 0;

    

    while (stop != -1)
    {

    printf("enter option :");
    scanf("%d", &option);

    if (option == 0)
    {
        flag++;
        printf("enter size :");
        scanf("%d", &s);
        size += size;

        tasks = (task*)malloc(size * sizeof(task));
        if (tasks == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
        
        printf("<-----------------add tasks---------------->\n");
        add_tasks(tasks, size);
    }
    if (option == 1)
    {
        size++;
        if (flag > 0)
        {
            printf("realoc\n");
            tasks = (task*)realloc(tasks, (size * sizeof(task)));
            if (tasks == NULL) {
                printf("Memory allocation failed!!");
                return 1;
            }
        }
        if (flag == 0)
        {
            flag++;
            printf("malloc\n");
            tasks = (task*)malloc(size * sizeof(task));
            if (tasks == NULL) {
                printf("Memory allocation failed");
                return 1;
            }
        }

        printf("<---------------add one task--------------->\n");
        add_task(tasks, &size);
    }
    if (option == -1)
        stop = -1;

    printf("<-------------display all tasks------------>\n");
    display_tasks(tasks, size);
    }

    /* 
    task* tasks = (task*)malloc(size * sizeof(task));
    if (tasks == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    
    

    
    printf("<-----------------add tasks---------------->\n");
    add_tasks(tasks, size);
    printf("<-------------display all tasks------------>\n");
    display_tasks(tasks, size);
    printf("<---------------add one task--------------->\n");
    size++;
    if (is_Emty(tasks, (size - 1)))
    {
        printf("realoc\n");
        tasks = (task*)realloc(tasks, (size * sizeof(task)));
        if (tasks == NULL) {
            printf("Memory allocation failed!!");
            return 1;
        }
    }
    else 
    {
        tasks = (task*)malloc(size * sizeof(task));
        printf("malloc\n");
        if (tasks == NULL) {
            printf("Memory allocation failed!!");
            return 1;
        }
    }
    add_task(tasks, &size);
    printf("%d\n", size);
    printf("<-------------display all tasks------------>\n");
    display_tasks(tasks, size);
    */

    free(tasks);
    printf("nice you make it :)");
}
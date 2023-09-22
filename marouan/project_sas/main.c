#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// reading data from file -----> test not working 
// search by anything ---------> completd
// collaborateur list ---------> started

typedef struct date
{
    int day;
    int month;
    int year;
} Date;

typedef struct task
{
    int id;
    char title[50];
    char description[100];
    Date deadline;
    char status[50];
    Date date;
} task;

typedef struct coWorker
{
    char first_name[30];
    char last_name[30];
    char email[50];
} coWorker;

// is valid funcction is not completed yet
bool is_valid_date (int day, int month, int year)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    if (year < 1900 || year > 2100)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;
    
    //February conndition check
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29)
                return false;
        } else {
            if (day > 28)
                return false;
        }
    }

    if (year > tm.tm_year + 1900 || (year == tm.tm_year + 1900 && month > tm.tm_mon + 1) 
        || (year == tm.tm_year + 1900 && month == tm.tm_mon + 1 && day >= tm.tm_mday))
        return true;

    return false;
}


// convert date to number if days 
int date_to_days(Date date) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = date.year - 1900;
    timeinfo.tm_mon = date.month - 1;
    timeinfo.tm_mday = date.day;

    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;

    time_t epochTime = mktime(&timeinfo);
    int days = (epochTime / (60 * 60 * 24));
    return days;
}

int days_left(Date current_date, Date given_date) {
    int current_days = date_to_days(current_date);
    int given_days = date_to_days(given_date);

    return  given_days - current_days;
}

void display_task(task t)
{
    printf("id : %d\n", t.id);
    printf("title : %s\n", t.title);
    printf("description : %s\n", t.description);
    printf("deadline : %d-%d-%d\n", t.deadline.day, t.deadline.month, t.deadline.year);
    printf("status : %s\n", t.status);
    printf("Creation Date : %d-%d-%d\n", t.date.day, t.date.month, t.date.year);
    printf("---------------------->\n");
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
    char str[99];
    char new_str[100];

    tasks[size - 1].id = size;
    printf("title :");
    scanf("%c",&temp);
	fgets(tasks[size - 1].title, 50, stdin);
    tasks[size - 1].title[strcspn(tasks[size - 1].title, "\n")] = '\0';

    printf("description :");
    scanf("%c",&temp1);
	fgets(str, 99, stdin);
    str[strcspn(str, "\n")] = '\0';

    new_str[0] = temp1;
    new_str[1] = '\0';

    strcat(new_str, str);
    strcpy(tasks[size - 1].description, new_str);

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
    char str[99];
    char new_str[100];

    if(flag == 1)
        i = 0;
    else if (flag > 1)
        i = size;
    while (i < s)
    {
        tasks[i].id = i + 1;
        printf("title :");
        scanf("%c",&temp);
	    fgets(tasks[i].title, 50, stdin);
        tasks[i].title[strcspn(tasks[i].title, "\n")] = '\0';
        
        printf("description :");
        scanf("%c",&temp1);
	    fgets(str, 99, stdin);
        str[strcspn(str, "\n")] = '\0';

        new_str[0] = temp1;
        new_str[1] = '\0';

        strcat(new_str, str);
        strcpy(tasks[i].description, new_str);

        
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

// sort still not competed yet ------> done--;
// task 3 :  task that have 3 day or les for deadline -----> completed
// test sort by deadline ---> logic done
void display_tasks_sorted (task *tasks, int size, int sort_type)
{
    int i;
    int j;
    task tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (sort_type == 1)
            {
                if (tasks[i].title[0] > tasks[j].title[0])
                {
                    tmp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = tmp;
                }
            }
            else if (sort_type == 2)
            {
                if (tasks[i].deadline.year > tasks[j].deadline.year)
                {
                    tmp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = tmp;
                }
                else if (tasks[i].deadline.year == tasks[j].deadline.year)
                {
                    if (tasks[i].deadline.month > tasks[j].deadline.month)
                    {
                        tmp = tasks[i];
                        tasks[i] = tasks[j];
                        tasks[j] = tmp;
                    }
                    else if (tasks[i].deadline.month == tasks[j].deadline.month)
                    {
                        if (tasks[i].deadline.day > tasks[j].deadline.day)
                        {
                            tmp = tasks[i];
                            tasks[i] = tasks[j];
                            tasks[j] = tmp;
                        }
                    }
                }
            }
            else if (sort_type == 3)
            {
                int i = 0;
                Date current_date;
                Date given_date;

                time_t t;
                t = time(NULL);
                struct tm tm = *localtime(&t);

                current_date.day = tm.tm_mday;
                current_date.month = tm.tm_mon+1;
                current_date.year = tm.tm_year+1900;
                
                while (i < size)
                {
                    given_date = tasks[i].deadline;
                
                    if (days_left(current_date, given_date) <= 3)
                    {
                        printf("--------> %d day left\n", days_left(current_date, given_date));
                        display_task(tasks[i]);
                    }
                    i++;
                }  
            }
            j++;
        }
        i++;
    }
}

void modify_task (task *tasks, int size, int modify_option)
{
    int i;
    int task_index = -1;
    int id;
    char temp;
    int error = 0;
    int print_error = 0;
    char handler[10];

    printf("enter the id of task u wanna update:");
    scanf("%s", handler);
    id = atoi(handler);

    i = 0;
    while (i < size && task_index == -1)
    {
        printf("1\n");
        if(id == tasks[i].id)
            task_index = i;
        i++;
    }

    if (task_index == -1)
        printf("can not be found !!!!!!\n");
    else
    {
        printf("task you wanna modify --> %d : %s\n", id, tasks[task_index].title);
        if (modify_option == 1)
        {
            printf("new description :");
            scanf("%c",&temp);
	        fgets(tasks[task_index].description, 100, stdin);
            tasks[task_index].description[strcspn(tasks[task_index].description, "\n")] = 0;
        }
        else if (modify_option == 2)
        {
            while (error == 0)
            {   
                if (print_error == 1)
                {
                    printf("error!!!!!\n");
                    printf("status ----> (todo , doing, done)\n");
                }   
                printf("new status :");
                scanf("%s", tasks[task_index].status);
                if (strcmp(tasks[task_index].status, "todo") == 0 || 
                    strcmp(tasks[task_index].status, "doing") == 0 || 
                    strcmp(tasks[task_index].status, "done") == 0)
                {
                    error = 1;
                }
                else print_error = 1;
            }

            error = 0;
            print_error = 0;

        }
        else if (modify_option == 3)
        {
            while (error == 0)
            {   
                if (print_error == 1)
                {
                    printf("error!!!!!\n");
                    printf("invalid date ----> try again!!!!\n");
                }
                printf("new Deadline :\n");
                printf("day :");
                scanf("%d", &tasks[task_index].deadline.day);
                printf("month :");
                scanf("%d", &tasks[task_index].deadline.month);
                printf("year :");
                scanf("%d", &tasks[task_index].deadline.year);
                if (is_valid_date(tasks[task_index].deadline.day, 
                    tasks[task_index].deadline.month, 
                    tasks[task_index].deadline.year))
                {
                    error = 1;
                }
                else print_error = 1;
            }

            error = 0;
            print_error = 0;
        }
    }
}

int delete_task (task *tasks, int *size)
{
    int i;
    int task_index = -1;
    int id;
    int to_continue = 0;
    int passed = 0;

    printf("enter the id of task you wanna delete: :");
    scanf("%d", &id);

    i = 0;
    while (i < (*size) && task_index == -1)
    {
        if(id == tasks[i].id)
            task_index = i;
        i++;
    }
    printf("pass\n");
    if (task_index == -1)
    {
        printf("can not be found !!!!!!\n");
    }     
    else
    {
        printf("you sure you want to delete --> %d --> : %s\n", id, tasks[task_index].title);
        printf("enter 1 to continue 0 to quite :");
        scanf("%d", &to_continue);

        if (to_continue == 1)
        {
            i = task_index;
            while (i < (*size) - 1)
            {
                tasks[i] = tasks[i + 1];
                i++;
            }

            (*size)--;
            passed++;
        }
    }
    return passed;
}

void search_task(task *tasks, int size, int search_option)
{
    int i;
    int task_index = -1;
    int id;
    char title[50];
    char temp;

    i = 0;
    if (search_option == 1)
    {
        printf("enter the id of task you wanna search for :");
        scanf("%d", &id);

        while (i < size && task_index == -1)
        {   
            if(id == tasks[i].id)
                task_index = i;
            i++;
        }
        if (task_index == -1)
            printf("task not found !!!!\n");
        else display_task(tasks[task_index]);
    }
    else if (search_option == 2)
    {
        printf("enter the title of task you wanna search for :");
        scanf("%c",&temp);
	    fgets(title, 50, stdin);
        title[strcspn(title, "\n")] = 0;

        while (i < size && task_index == -1)
        {   
            if(strcmp(title, tasks[i].title) == 0)
                task_index = i;
            i++;
        }
        if (task_index == -1)
            printf("task not found !!!!\n");
        else display_task(tasks[task_index]);
    }
    else if (search_option == 3)
    {
        int op;
        printf("<------------------search for by------------------->\n");
        printf("< search options :                                 >\n");
        printf("< 1 to search by creation date.                    >\n");
        printf("< 2 to search by deadline.                         >\n");
        printf("< 0 quit.                                          >\n");
        printf("<-------------------------------------------------->\n");
        printf("enter your choice:");
        scanf("%d", &op);

        if (op == 1)
        {
            Date date;
            printf("enter the date you wanna search for (dd-mm-year) :");
            scanf("%d-%d-%d", &date.day, &date.month, &date.year);

            while (i < size)
            {   
                if((date.day == tasks[i].date.day && date.month == tasks[i].date.month) && 
                    date.year == tasks[i].date.year)
                {
                    task_index = i;
                    display_task(tasks[i]);
                }
                i++;
            }

            if (task_index == -1) printf("no tasks with matching date!!!!!\n");
        }
        else if (op == 2)
        {
            Date date;
            printf("enter the deadline you wanna search for (dd-mm-year) :");
            scanf("%d-%d-%d", &date.day, &date.month, &date.year);

            while (i < size)
            {   
                if((date.day == tasks[i].deadline.day && date.month == tasks[i].deadline.month) && 
                    date.year == tasks[i].deadline.year)
                {
                    task_index = i;
                    display_task(tasks[i]);
                }
                i++;
            }

            if (task_index == -1) printf("no tasks with matching deadline!!!!\n");
        }
    }
}

void search_by(task *tasks, int size)
{

}

int total_finished_tasks(task *tasks, int size)
{
    int total = 0;
    int i;

    i = 0;
    while (i < size)
    {
        if (strcmp(tasks[i].status, "done") == 0)
            total++;
        i++;
    }
    return total;
}

int total_not_finished_tasks(task *tasks, int size)
{
    int total = 0;
    int i;

    i = 0;
    while (i < size)
    {
        if (strcmp(tasks[i].status, "done") != 0)
            total++;
        i++;
    }
    return total;
}

void days_left_in_deadline (task *tasks, int size)
{
    int i;
    Date current_date;
    Date given_date;

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    current_date.day = tm.tm_mday;
    current_date.month = tm.tm_mon+1;
    current_date.year = tm.tm_year+1900;

    i = 0;          
    while (i < size)
    {
        given_date = tasks[i].deadline;

        printf("task : ID -----> %d\n", tasks[i].id);
        printf("-------> %d day left\n", days_left(current_date, given_date));
        printf(">\n");

        i++;
    }
}

void read_data(task *tasks)
{
    FILE *data;
    int i = 0;

    data = fopen("data.txt", "r");

    if (data == NULL) {
        perror("Error opening file");
        return;
    }

    while (i < 3 && fscanf(data, "%d\n%49[^\n]\n%99[^\n]\n%d-%d-%d\n%s\n%d-%d-%d\n",
        &tasks[i].id, tasks[i].title, tasks[i].description,
        &tasks[i].date.day, &tasks[i].date.month, &tasks[i].date.year,
        tasks[i].status,
        &tasks[i].date.day, &tasks[i].date.month, &tasks[i].date.year) == 10) {
        i++;
    }

    fclose(data);
}

int print_menu (int error)
{
    int choice;
    char holder[20];

    if (error == -1)
        printf("invalid choice!!! try again :) .\n");
    printf("*----------------------------MENU-----------------------------*\n");
    printf("* Press 1 to add multible tasks.                              *\n");
    printf("* Press 2 to add one task.                                    *\n");
    printf("* Press 3 to disalay tasks.                                   *\n");
    printf("* Press 4 to modify a task.                                   *\n");
    printf("* Press 5 to delete a task.                                   *\n");
    printf("* Press 6 to search for a task.                               *\n");
    printf("* Press 7 to display statistics.                              *\n");
    printf("* Press -1 to quit.                                           *\n");
    printf("*-------------------------------------------------------------*\n");
    printf("* Enter your choice:                                           \n");
    scanf("%s", holder);

    choice = atoi(holder);
    if (choice == 0)
        choice = -2;

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

    //coWorker cw;
    //cw.tasks[size];

    /*
    tasks = (task*)malloc(3 * sizeof(task));
    if (tasks == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    read_data(tasks);
    */

    while (stop != -1)
    {

        option = print_menu(0);

        if (option == 1)
        {
            char holder[10];
            printf("enter size :");
            scanf("%s", holder);
            s = atoi(holder);
            if (s == 0)
                printf("unvalid input !!!!!\n");
            else
            {
                
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
        
                printf("<---------------------------add tasks------------------------->\n");
                add_tasks(tasks, size1, size, flag);
            }
        }
        if (option == 2)
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

            printf("<-------------------------add one task------------------------>\n");
            add_task(tasks, size);
        }
        if (option == 3)
        {
            int sort_option;
            char holder[10];
            printf("<------------------display all tasks--------------->\n");
            printf("< how you wanna display tasks :                    >\n");
            printf("< 1 sorted by alphabetical order :                 >\n");
            printf("< 2 sorted by deadline :                           >\n");
            printf("< 3 tasks that has 3 days or less for deadline.    >\n");
            printf("< 4 display :                                      >\n");
            printf("<-------------------------------------------------->\n");
            printf("enter your choice:");
            sort_option = atoi(holder);
            //scanf("%d", &sort_option);
            if (sort_option >= 1 && sort_option < 4)
            {
                printf("<---------------------------display--------------------------->\n");
                display_tasks_sorted(tasks, size, sort_option);
                if (sort_option != 3)
                    display_tasks(tasks, size);
            }
            else if (sort_option == 4)
            {
                printf("<---------------------------display--------------------------->\n");
                display_tasks(tasks, size);
            }
            else if (sort_option == 0)
            {
                printf("unvalid input !!!!!\n");
            }
        }
        if (option == 4)
        {
            int modify_option;
            char holder[10];
            printf("<-------------------modify all tasks--------------->\n");
            printf("< modification options :                           >\n");
            printf("< 1 to modify description.                         >\n");
            printf("< 2 to modify status.                              >\n");
            printf("< 3 to modify deadline.                            >\n");
            printf("< -1 quit.                                         >\n");
            printf("<-------------------------------------------------->\n");
            printf("enter your choice:");
            scanf("%s", holder);
            modify_option = atoi(holder);
            //scanf("%d", &modify_option);
            if (modify_option >= 1 && modify_option <= 3)
                modify_task(tasks, size, modify_option);
            else if (modify_option == 0)
                printf("unvalid input !!!!!\n");
        }
        if (option == 5)
        {
            printf("<---------------------------delete--------------------------->\n");
            int passed = delete_task(tasks, &size);
            if (passed == 1)
            {
                tasks = (task*)realloc(tasks, (size * sizeof(task)));

                if (size == 0) {
                    free(tasks);
                    tasks = NULL;
                }
            }
        }
        if (option == 6)
        {
            int search_option;
            char handler[10];
            printf("<-----------------search for tasks----------------->\n");
            printf("< search options :                                 >\n");
            printf("< 1 to search by ID.                               >\n");
            printf("< 2 to search by title.                            >\n");
            printf("< 3 other.                                         >\n");
            printf("< -1 quit.                                          >\n");
            printf("<-------------------------------------------------->\n");
            printf("enter your choice:");
            scanf("%s", handler);
            search_option = atoi(handler);
            if (search_option >= 1 && search_option <= 3)
                search_task(tasks, size, search_option);
            else if (search_option == 0)
                printf("unvalid input !!!!!\n");
        }
        if (option == 7)
        {
            int statistics_option;
            char handler[10];
            printf("<--------------------statistics-------------------->\n");
            printf("< statistics options :                             >\n");
            printf("< 1 for total number of tasks.                     >\n");
            printf("< 2 for finished tasks and not.                    >\n");
            printf("< 3 for number of days for deadline.               >\n");
            printf("< -1 quit.                                          >\n");
            printf("<-------------------------------------------------->\n");
            printf("enter your choice:");
            scanf("%s", handler);
            statistics_option = atoi(handler);
            if (statistics_option == 1)
            {
                printf("<------------------------total tasks------------------------->\n");
                printf("total number of tasks : %d\n", size);
            }
            else if (statistics_option == 2)
            {
                printf("<----------------------finished tasks------------------------>\n");
                printf("number of finished tasks : %d\n", total_finished_tasks(tasks, size));
                printf("number of not finished tasks : %d\n", total_not_finished_tasks(tasks, size));
            }
            else if (statistics_option == 3)
            {
                printf("<-------------------days left in deadline-------------------->\n");
                days_left_in_deadline (tasks, size);
            }
            else if (statistics_option = 0)
            {
                printf("unvalid input !!!!!\n");
            }
        }
        if (option == -2)
            printf("error!!!! you enterd a string insted of integer\n");
        if (option == -1)
            stop = -1;
    }

    int save = 0;
    char save_handler[10];
    printf("<---------------------------save tasks--------------------------->\n");
    printf("do you wanna save the data before you quit !!!\n");
    printf("Press 1 (any other value will quit without saving) :\n");
    scanf("%s", save_handler);
    save = atoi(save_handler);
    if (save == 1)
    {
        FILE *data;
        int i;

        data = fopen("data.txt", "a");

        i = 0;
        while (i < size)
        {
            fprintf(data, "%d\n", tasks[i].id);
            fprintf(data, "%s\n", tasks[i].title);
            fprintf(data, "%s\n", tasks[i].description);
            fprintf(data, "%d-%d-%d\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
            fprintf(data, "%s\n", tasks[i].status);
            fprintf(data, "%d-%d-%d\n", tasks[i].date.day, tasks[i].date.month, tasks[i].date.year);
            i++;
        }
        fclose(data);
    }

    free(tasks);
    printf("nice, you make it :)\n");
}
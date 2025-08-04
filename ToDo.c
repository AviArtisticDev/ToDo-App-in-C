#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>

int todosCount = 0; // For Count the ToDO
FILE *fp;

// Structure of ToDo
struct Todo {
    char title[50];
    char createdAt[50];
    _Bool isCompleted;
} todos[20];

// Function to Save all ToDos in a File
void saveToFile()
{
    fp = fopen("todos.bin", "w"); 
    if (!fp)
    {
        printf("Can't save your file\n");
    } 
    else
    {
        for (int i = 0; i < todosCount; i++)
        {
            fwrite(&todos[i], sizeof(struct Todo), 1, fp);
        }
        fclose(fp);
    }
}

// Function to know that, How many ToDos are Saved in File
void getFileSize()
{
    fseek(fp, 0L, SEEK_END);
    unsigned int long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    todosCount = size/sizeof(struct Todo);
}

// Function for read all ToDos from file
void readFromFile()
{
    fp = fopen("todos.bin", "r");
    if (!fp)
    {
        printf("We are not able to find any todos file\n");
    }
    else
    {
        getFileSize();
        for (int i = 0; i < todosCount; i++)
        {
            fread(&todos[i], sizeof(struct Todo), 1, fp);
        }
        fclose(fp);
    }
}

// Function to add New ToDo
void addToDo()
{
    // for todo title
    char userInput[50];
    printf("Type your ToDo\n>> ");
    scanf("%[^\n]s", userInput);
    strncpy(todos[todosCount].title, userInput, sizeof(todos[0].title));

    // add time
    char todoTime[50];

    struct tm cTime;
    time_t timeS = time(NULL); 
    localtime_s(&cTime, &timeS);

    // format 30/7 11:40
    snprintf(todoTime, 50, "%02i/%02i %02i:%02i", cTime.tm_mday, cTime.tm_mon + 1, cTime.tm_hour, cTime.tm_min);
    strcpy(todos[todosCount].createdAt, todoTime);

    // set Boolean to false
    todos[todosCount].isCompleted = false; 
    todosCount++;
}

// Function to Print all ToDos
void printAllToDo()
{
    printf("__________________________________________________________________________________\n");
    printf("|  Id  |                    Title                    |   Created At   |  Status  |\n");
    printf("+------+---------------------------------------------+----------------+----------+\n");
    
    for (int i = 0; i < todosCount; i++)
    {
        if (todos[i].isCompleted)
        {
            printf("\033[10m");
        }
        else
        {
            printf("\033[1m");
        }
        
        printf("| %-3d  | %-43s | %-14s | %-8s |\n", i + 1, todos[i].title, todos[i].createdAt, (!todos[i].isCompleted) ? "No" : "Yes");
        printf("+------+---------------------------------------------+----------------+----------+\n"); 
    }
}

// Function to Mark Complete Status
void markAsComplete()
{
    int todoId;
    printf("Enter the Id to mark todo\n>>");
    scanf("%d", &todoId);
    todoId--;
    if (todoId < 0 || todoId > todosCount)
    {
        printf("Invalid todo id\n");
    }
    else
    {
        todos[todoId].isCompleted = true;
        printf("ToDo mark as Completed.");
    }
}

// FUnction to Delete ToDos
void deleteTodo()
{
    int todoId;
    printf("Enter the Id to delete todo\n>>");
    scanf("%d", &todoId);
    if (todoId < 0 || todoId > todosCount)
    {
        printf("Invalid todo id\n");
    }
    else
    {
        todoId--;
        memmove(todos + todoId, todos + todoId + 1, (todosCount - todoId - 1) * sizeof(*todos)); 
        todosCount--;
        printf("your todo has been deleted.\n");
    }   
}

// Function to Show Options
void ShowOptions()
{
    char userChoice;
    printf("Type 'A' to ADD, 'D' to DELETE,'C' to MARK COMPLETE and 'Q' to Quit.\n>>");
    userChoice = toupper(getchar());
    getchar();
    switch (userChoice)
    {
    case 'A':
        addToDo();
        break;
    case 'D':
        deleteTodo();
        break;
    case 'C':
        markAsComplete();
        break;
    case 'Q':
        exit(0);
        break;
    default:
        printf("Command not found.\n");
        ShowOptions();
        break;
    }
    saveToFile();
    system("@cls");
    printAllToDo();
    getchar();
    ShowOptions();
}

void isThisFirstTime()
{
    if (access("todos.bin", F_OK) != -1)
    {
        readFromFile();
        printAllToDo();
        ShowOptions();
    }
    else
    {
        printf("Welcome to the ToDo App\n");
        addToDo();
        saveToFile();
        printAllToDo();
        ShowOptions();
    }
}

int main()
{
    system("@cls");  // For Clear the Screen
    printf("\033[32;1m");
    isThisFirstTime();
}



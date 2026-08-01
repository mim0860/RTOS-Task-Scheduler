#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "queue.h"
#include "scheduler.h"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

void loadTasks(PriorityQueue *q)
{
    initQueue(q);
     FILE *fp = fopen("tasks.txt", "r");

    if(fp == NULL)
    {
        printf("Error! Cannot open tasks.txt\n");
        return;
    }

    Task t;

    while(fscanf(fp,"%d %d %d",
                 &t.id,
                 &t.priority,
                 &t.burstTime) == 3)
    {
        t.remainingTime = t.burstTime;
        t.waitingTime = 0;
        t.turnaroundTime = 0;

        enqueue(q, t);
    }

    fclose(fp);

   // printf("\nTasks Loaded Successfully!\n");
}
    void showProjectInfo()
{
    printf("\n");

printf(CYAN);
printf("============================================================\n");
printf("                 PROJECT INFORMATION\n");
printf("============================================================\n");
printf(RESET);

printf(YELLOW "Project Title : " RESET "RTOS Priority Round Robin Scheduler\n");
printf(YELLOW "Team Name     : " RESET "Triple Spark (Group-05)\n\n");

printf(GREEN "Team Members:\n" RESET);

printf(WHITE "1. Sumaiya Islam Mim           (241-115-242)\n" RESET);
printf(WHITE "2. Kaniz Fatema Tumpa          (241-115-240)\n" RESET);
printf(WHITE "3. MST. Suraiya Mostofa Mariya (231-115-269)\n\n" RESET);

printf(CYAN "University : " RESET "Metropolitan University\n");
printf(CYAN "Department : " RESET "B.Sc. in CSE\n");
printf(CYAN "Course     : " RESET "Operating System Lab\n");
printf(CYAN "Instructor : " RESET "Khalid Bin Selim\n");

printf("\n");

printf(CYAN);
printf("============================================================\n");
printf(RESET);
}
void pauseScreen()
{
    printf("\n=============================================\n");
    printf(BLUE"Press ENTER to return to Main Menu..."RESET);
    printf("\n=============================================\n");

    getchar();
    getchar();
    system("cls");
}

int main()
{
    PriorityQueue q;
    initQueue(&q);
    loadTasks(&q);
   // printf("Queue Size = %d\n", q.size);
    //displayQueue(&q);
    
    

    // Time Quantum = 2 ms
   // runScheduler(&q, 2);
    int choice;
    int running = 1;
    printf(CYAN);
    printf("\n");
    printf("============================================================\n");
    printf("              WELCOME TO RTOS TASK SCHEDULER\n");
    printf("============================================================\n");
    printf(RESET);

    printf(YELLOW);
    printf("          Priority Round Robin Scheduling System\n");
    printf(RESET);

    printf(GREEN);
    printf("                Triple Spark (Group-05)\n");
    printf(RESET);

    printf(BLUE);
    printf("\n                Metropolitan University\n");
    printf("         Department of Computer Science & Engineering\n");
    printf("                Operating System Lab Project\n\n");
    printf(RESET);

    while(running)
{
    printf(WHITE);
    printf("\n====================================================\n");
    printf("      RTOS PRIORITY ROUND ROBIN SCHEDULER\n");
    printf("           Triple Spark (Group-05)\n");
    printf("====================================================\n");

  printf(CYAN);
printf("\n====================================================\n");
printf("                    MAIN MENU\n");
printf("====================================================\n");
printf(RESET);

printf(YELLOW "[1] " RESET);
printf(WHITE  "Project Information\n" RESET);

printf(YELLOW "[2] " RESET);
printf(WHITE  "Display Ready Queue\n" RESET);

printf(YELLOW "[3] " RESET);
printf(WHITE  "Run Scheduler\n" RESET);

printf(YELLOW "[4] " RESET);
printf(WHITE  "Reload Tasks\n" RESET);

printf(YELLOW "[5] " RESET);
printf(WHITE  "Exit\n" RESET);

printf(BLUE "\nEnter Your Choice : " RESET);
    scanf("%d", &choice);
   if(choice == 1)
{
    showProjectInfo();
    pauseScreen();
}
else if(choice == 2)
{
    displayQueue(&q);
    pauseScreen();
}
else if(choice == 3)
{
    
    PriorityQueue tempQueue = q;   // Queue-এর Copy

    runScheduler(&tempQueue, 2);
    

    pauseScreen();
}
else if(choice == 4)
{
    loadTasks(&q);
    printf(GREEN);
    printf("\nTasks Reloaded Successfully!\n");
    printf(RESET);
    pauseScreen();
}
else if(choice == 5)
{
    printf("\n");

printf(CYAN);
printf("============================================================\n");
printf("                 THANK YOU FOR USING\n");
printf("============================================================\n");
printf(RESET);

printf(GREEN);
printf("          RTOS PRIORITY ROUND ROBIN SCHEDULER\n");
printf("                 Triple Spark (Group-05)\n");
printf(RESET);

printf(YELLOW);
printf("\n        Project Demonstration Completed Successfully!\n");
printf(RESET);

printf(BLUE);
printf("\n                 See You Again!\n");
printf(RESET);

printf(CYAN);
printf("============================================================\n");
printf(RESET);
    running = 0;
}
else
{
    printf("\nInvalid Choice!\n");
}
}
        return 0;
 }


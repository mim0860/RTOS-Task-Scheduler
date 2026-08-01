#include <stdio.h>
#include <string.h>
#include "scheduler.h"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"


void applyAging(PriorityQueue *q)
{
    for(int i = 0; i < q->size; i++)
    {
        if(q->tasks[i].priority < 10)
            q->tasks[i].priority++;
    }
}

void runScheduler(PriorityQueue *q, int timeQuantum)
{
    printf("=============================================================\n");
    printf("        RTOS PRIORITY ROUND ROBIN SCHEDULER\n");
    printf("              Triple Spark (Group-05)\n");
    printf("=============================================================\n");

    int currentTime = 0;
    int contextSwitches = 0;

    int completedTasks = 0;
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    char gantt[500] = "";
    char timeline[500] = "0";
    char border[500] = "";

    printf("\nInitial Queue:\n");
    displayQueue(q);

    printf("\n========== ROUND ROBIN SCHEDULER ==========\n");

    while(q->size > 0)
    {
        printf("\n---------------------------------\n");
        printf("READY QUEUE BEFORE EXECUTION\n");
        displayQueue(q);
        printf("---------------------------------\n");

        applyAging(q);

        Task current = dequeue(q);

        contextSwitches++;

        //printf("\nCPU EXECUTING --> T%d ", current.id);
        printf("\n");
    
        printf(CYAN "=============================================================\n" RESET);
printf(CYAN "                     CPU STATUS\n" RESET);
printf(CYAN "=============================================================\n" RESET);

printf(GREEN " Current Task   : T%d\n" RESET, current.id);
printf(YELLOW " Status         : RUNNING\n" RESET);
                int executedTime;

        if(current.remainingTime > timeQuantum)
        {
            executedTime = timeQuantum;

           printf(BLUE " Time Slice     : %d ms\n" RESET, executedTime);

            current.remainingTime -= executedTime;
        }
        else
        {
            executedTime = current.remainingTime;

           printf(BLUE " Executed       : %d ms\n" RESET, executedTime);
           printf(GREEN " Status         : COMPLETED\n" RESET);

            current.remainingTime = 0;
        }

        currentTime += executedTime;

        /* ---------- GANTT CHART DATA ---------- */

        char temp[50];

        
        sprintf(temp, "|T%-2d ", current.id);
        strcat(gantt, temp);

        strcat(border, "+-------");

        sprintf(temp, "%5d", currentTime);
        strcat(timeline, temp);

        /* -------------------------------------- */

        printf(MAGENTA " Current Time  : %d ms\n" RESET, currentTime);
printf(CYAN " Remaining    : %d ms\n" RESET, current.remainingTime);

        if(current.remainingTime > 0)
        {
            enqueue(q, current);
        }
        else
        {
            completedTasks++;

            current.turnaroundTime = currentTime;
            current.waitingTime = current.turnaroundTime - current.burstTime;

            totalWaitingTime += current.waitingTime;
            totalTurnaroundTime += current.turnaroundTime;

           printf(CYAN "-------------------------------------------------------------\n" RESET);

printf(GREEN "*** Task %d Completed Successfully\n" RESET, current.id);

printf(CYAN "-------------------------------------------------------------\n" RESET);

printf(YELLOW "Remaining Tasks : %d\n" RESET, q->size);

printf(BLUE "Waiting Time    : %d ms\n" RESET, current.waitingTime);

printf(MAGENTA "Turnaround Time : %d ms\n" RESET, current.turnaroundTime);
        }

        //printf("\n");
        //displayQueue(q);
            }   // <-- while loop ends here

    /* ================= GANTT CHART ================= */

    //strcat(border, "+-----");

   printf("\n");

printf(CYAN);
printf("=============================================================\n");
printf("                     GANTT CHART\n");
printf("=============================================================\n");
printf(RESET);
   printf(CYAN);
printf("%s\n", border);
printf(RESET);

printf("%s|\n", gantt);

printf(CYAN);
printf("%s\n", border);
printf(RESET);

printf(YELLOW);
printf("%s\n", timeline);
printf(RESET);
printf("\n");

printf(MAGENTA);
printf("-------------------------------------------------------------\n");
printf("                 GANTT CHART SUMMARY\n");
printf("-------------------------------------------------------------\n");
printf(RESET);

printf(GREEN);
printf(" Scheduling Algorithm : Priority Round Robin\n");
printf(RESET);

printf(YELLOW);
printf(" Time Quantum         : %d ms\n", timeQuantum);
printf(RESET);

printf(CYAN);
printf(" Total Execution Time : %d ms\n", currentTime);
printf(RESET);

printf(MAGENTA);
printf("-------------------------------------------------------------\n");
printf(RESET);
    printf("=============================================================\n");

    /* ============== FINAL STATISTICS ============== */

    printf("\n");

printf(CYAN);
printf("=============================================================\n");
printf("                  FINAL STATISTICS\n");
printf("=============================================================\n");
printf(RESET);

printf(CYAN "+----------------------------------------------------------+\n" RESET);

    printf(GREEN "| Tasks Completed         : %-18d |\n" RESET, completedTasks);

printf(YELLOW "| Context Switches        : %-18d |\n" RESET, contextSwitches);

printf(CYAN "| Total Execution Time    : %-15dms  |\n" RESET, currentTime);

printf(BLUE "| Average Waiting Time    : %-12.2f  ms   |\n" RESET,
       totalWaitingTime / completedTasks);

printf(MAGENTA "| Average Turnaround Time : %-12.2f  ms   |\n" RESET,
       totalTurnaroundTime / completedTasks);

printf(RED "| CPU Utilization         : %-15s    |\n" RESET, "100%");
   printf(CYAN "+----------------------------------------------------------+\n" RESET);

printf("\n");

printf("\n");

printf(GREEN);
printf("=============================================================\n");
printf("           ALL TASKS EXECUTED SUCCESSFULLY\n");
printf("=============================================================\n");
printf(RESET);


printf("\n");
}   // <-- runScheduler() ends here


scheduler.h

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "queue.h"

void runScheduler(PriorityQueue *q, int timeQuantum);

#endif



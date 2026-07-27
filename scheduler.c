#include <stdio.h>
#include <string.h>
#include "scheduler.h"

void runScheduler(PriorityQueue *q, int timeQuantum)
{
    printf("\n========== ROUND ROBIN SCHEDULER ==========\n");
    int currentTime=0;
    char gantt[500] = "";
    char timeline[500] = "0";
    char border[500] = "";
    int contextSwitches = 0;

    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    int completedTasks = 0;
    while (q->size > 0)
    {
        printf("\n---------------------------------\n");
        printf("READY QUEUE BEFORE EXECUTION:\n");
        displayQueue(q);
        printf("---------------------------------\n");
        Task current = dequeue(q);
        contextSwitches++;
        printf("\nCPU EXECUTING --> ");
        printf("| T%d ", current.id);
        char temp[20];
        sprintf(temp, "| T%d ", current.id);
        strcat(gantt, temp);
        strcat(border, "+------");
        char timeText[20];
        sprintf(timeText, "     %d", currentTime);
        strcat(timeline, timeText);
        if (current.remainingTime > timeQuantum)
        {
            printf(" for %d ms", timeQuantum);

            current.remainingTime -= timeQuantum;
            currentTime += timeQuantum;

            enqueue(q, current);
        }
        else
{
    printf(" for %d ms (Completed)", current.remainingTime);

    currentTime += current.remainingTime;
    char timeText[20];
    sprintf(timeText, "%7d", currentTime);
    strcat(timeline, timeText);
    
    sprintf(timeText, "    %d", currentTime);
    strcat(timeline, timeText);

    current.remainingTime = 0;

    current.turnaroundTime = currentTime;
    current.waitingTime = current.turnaroundTime - current.burstTime;

    totalWaitingTime += current.waitingTime;
    totalTurnaroundTime += current.turnaroundTime;
    completedTasks++;

    printf("\nTask %d Completed Successfully", current.id);
    printf("\nRemaining Tasks = %d\n", q->size);
    printf("\nWaiting Time = %d", current.waitingTime);
    printf("\nTurnaround Time = %d\n", current.turnaroundTime);
}
        printf("\n");
        printf(" | Current Time = %d ms\n", currentTime);
        displayQueue(q);
    }
    printf("\n==================================\n");
    printf("Average Waiting Time = %.2f\n",
       totalWaitingTime / completedTasks);

    printf("Average Turnaround Time = %.2f\n",
       totalTurnaroundTime / completedTasks);
    printf("==================================\n");
    printf("\nTotal Context Switches = %d\n", contextSwitches);
    printf("\n==============================\n");
    
    printf("GANTT CHART\n");
    strcat(border, "+");
    printf("\n======================== GANTT CHART ========================\n");

printf("%s\n", border);
printf("%s|\n", gantt);
printf("%s\n", border);
printf("%s\n", timeline);

printf("=============================================================\n");
       
    printf("==============================\n");
        printf("\n==============================\n");
        printf("FINAL STATISTICS\n");
        printf("==============================\n");
        printf("Tasks Completed      : %d\n", completedTasks);
        printf("Context Switches     : %d\n", contextSwitches);
        printf("Total Execution Time : %d ms\n", currentTime);
        printf("Average Waiting Time : %.2f ms\n",
        totalWaitingTime / completedTasks);
        printf("Average Turnaround Time : %.2f ms\n",
        totalTurnaroundTime / completedTasks);
        printf("==============================\n");
        printf("\nAll Tasks Finished!\n");
    }
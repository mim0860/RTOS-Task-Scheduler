#include<stdio.h>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#include"queue.h"

void initQueue(PriorityQueue*q)
{
    q->size=0;
}

void enqueue(PriorityQueue*q,Task t)
{
    int i=q->size-1;
    while(i>=0 && q->tasks[i].priority <t.priority)
    {
        q->tasks[i+1]=q->tasks[i];
        i--;
    }
    q->tasks[i+1]=t;
    q->size++;

}
Task dequeue(PriorityQueue*q)
{
    Task t=q->tasks[0];
    for(int i=0;i<q->size-1;i++){
        q->tasks[i]=q->tasks[i+1];
    }
    q->size--;
    return t;
}
void displayQueue(PriorityQueue *q)
{
    printf("\n");
    printf(CYAN "============================================================\n" RESET);
    printf(CYAN "                    READY QUEUE\n" RESET);
    printf(CYAN "============================================================\n" RESET);

printf("+------+----------+--------------+--------------+\n");
printf("| %sTask%s | %sPriority%s | %sBurst Time%s   | %sRemaining%s    |\n",
    YELLOW,RESET,
    CYAN,RESET,
    GREEN,RESET,
    MAGENTA,RESET);
printf("+------+----------+--------------+--------------+\n");
if(q->size == 0)
{
    printf(GREEN);
    printf("\n          ALL TASKS HAVE BEEN EXECUTED\n");
    printf(RESET);

    printf(CYAN "============================================================\n" RESET);

    return;
}

    for (int i = 0; i < q->size; i++)
    {
        printf("| T%-3d | %-8d | %-10dms | %-10dms |\n",
           q->tasks[i].id,
           q->tasks[i].priority,
           q->tasks[i].burstTime,
           q->tasks[i].remainingTime);
    }
    printf("+------+----------+--------------+--------------+\n");
}
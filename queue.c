#include<stdio.h>
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
    printf("\nPriority Queue:\n");

    for (int i = 0; i < q->size; i++)
    {
        printf("Task %d | Priority %d | Burst Time %d\n",
               q->tasks[i].id,
               q->tasks[i].priority,
               q->tasks[i].burstTime);
    }
}
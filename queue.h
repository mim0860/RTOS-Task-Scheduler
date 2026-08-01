#ifndef QUEUE_H
#define QUEUE_H
# include "task.h"
#define MAX_TASKS 10
typedef struct 
{
   Task tasks[MAX_TASKS];
   int size; 
}PriorityQueue;

void initQueue(PriorityQueue*q);
void enqueue(PriorityQueue*q,Task t);
Task dequeue(PriorityQueue*q);
void displayQueue(PriorityQueue*q);

#endif



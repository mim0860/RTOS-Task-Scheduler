#ifndef TASK_H
#define TASK_H

typedef struct
{
    int id;
    int priority;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
} Task;

#endif
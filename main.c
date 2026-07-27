#include <stdio.h>
#include "queue.h"
#include "scheduler.h"

int main()
{
    PriorityQueue q;
    initQueue(&q);

    Task t1 = {1, 3, 5, 5,0,0};
    Task t2 = {2, 1, 4, 4,0,0};
    Task t3 = {3, 2, 6, 6,0,0};

    enqueue(&q, t1);
    enqueue(&q, t2);
    enqueue(&q, t3);

    printf("Initial Queue:\n");
    displayQueue(&q);

    int timeQuantum = 2;

    runScheduler(&q, timeQuantum);

    return 0;
}
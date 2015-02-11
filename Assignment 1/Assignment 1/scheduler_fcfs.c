//
//  scheduler_fcfs.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/10/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_fcfs.h"
#include "helper_functions.h"

void finish_run(float averageWaitTime)
{
    printf("\nAverage Wait Time: %f\n", averageWaitTime);
}

void pop_ready_queue(struct ready_queue readyQueue, float timeElapsed, float numPops, float averageWaitTime)
{
    bool queueIsEmpty = (readyQueue.length <= 0);
    if (queueIsEmpty)
    {
        printf("\nQueue is empty! Please enlarge queue next time.\n");
    }
    if (queueIsEmpty || (timeElapsed >= TIME_LIMIT))
    {
        finish_run(averageWaitTime);
    }
    else
    {
        struct simulated_process nextProcess = readyQueue.processes[0];
        float newTimeElapsed;
        float newAverageWaitTime;
        float nextArrivalTime = nextProcess.arrivalTime;
        if (nextArrivalTime > timeElapsed)
        {
            newTimeElapsed = nextArrivalTime;
            newAverageWaitTime = ((((numPops - 1.0f) * averageWaitTime)
                                   + nextArrivalTime - timeElapsed) / numPops);
        }
        else
        {
            newAverageWaitTime = averageWaitTime;
            printf(" P%d", 0);
            ++readyQueue.processes;
            --readyQueue.length;
            newTimeElapsed = timeElapsed + nextProcess.expectedRunTime;
        }
        pop_ready_queue(readyQueue, newTimeElapsed, (numPops + 1.0f), newAverageWaitTime);
    }
}

void schedule_fcfs(struct ready_queue readyQueue)
{
    printf("First Come, First Served:\nTime Line:");
    float timeElapsed = 0.0f;
    pop_ready_queue(readyQueue, timeElapsed, 1.0f, 0.0f);
}
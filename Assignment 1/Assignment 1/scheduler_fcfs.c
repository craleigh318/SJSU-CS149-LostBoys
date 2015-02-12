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

void pop_ready_queue(struct ready_queue readyQueue, float timeElapsed, int numPops, float averageWaitTime)
{
    bool queueIsEmpty = (numPops >= readyQueue.length);
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
        struct simulated_process nextProcess = readyQueue.processes[numPops];
        float newTimeElapsed;
        float newAverageWaitTime;
        float nextArrivalTime = nextProcess.arrivalTime;
        int newNumPops;
        if (nextArrivalTime > timeElapsed)
        {
            newTimeElapsed = nextArrivalTime;
            newNumPops = numPops;
            newAverageWaitTime = ((((float)(numPops) * averageWaitTime)
                                   + nextArrivalTime - timeElapsed) / (float)(numPops + 1));
        }
        else
        {
            newAverageWaitTime = averageWaitTime;
            newNumPops = numPops + 1;
            printf(" P%d", numPops);
            newTimeElapsed = timeElapsed + nextProcess.expectedRunTime;
        }
        pop_ready_queue(readyQueue, newTimeElapsed, newNumPops, newAverageWaitTime);
    }
}

void schedule_fcfs(struct ready_queue readyQueue)
{
    printf("First Come, First Served:\nTime Line:");
    float timeElapsed = 0.0f;
    pop_ready_queue(readyQueue, timeElapsed, 0, 0.0f);
}
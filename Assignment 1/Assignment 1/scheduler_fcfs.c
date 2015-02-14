//
//  scheduler_fcfs.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/10/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_fcfs.h"
#include "helper_functions.h"

void finish_run(struct scheduler_statistics statistics)
{
    printf("\nWait Time: %f\n\n", statistics.waiting_time);
}

void pop_ready_queue(struct ready_queue readyQueue, struct scheduler_statistics statistics, float timeElapsed)
{
    int numPops = statistics.throughput;
    bool queueIsEmpty = (numPops >= readyQueue.length);
    if (queueIsEmpty)
    {
        printf("\nQueue is empty! Please enlarge queue next time.\n");
    }
    if (queueIsEmpty || (timeElapsed >= TIME_LIMIT))
    {
        finish_run(statistics);
    }
    else
    {
        struct simulated_process nextProcess = readyQueue.processes[numPops];
        float newTimeElapsed;
        float nextArrivalTime = nextProcess.arrivalTime;
        if (nextArrivalTime > timeElapsed)
        {
            newTimeElapsed = nextArrivalTime;
            statistics.waiting_time += (nextArrivalTime - timeElapsed);
        }
        else
        {
            ++statistics.throughput;
            printf(" P%d", statistics.throughput);
            newTimeElapsed = timeElapsed + nextProcess.expectedRunTime;
        }
        pop_ready_queue(readyQueue, statistics, newTimeElapsed);
    }
}

void schedule_fcfs(struct ready_queue readyQueue)
{
    printf("First Come, First Served:\nTime Line:");
    pop_ready_queue(readyQueue, new_scheduler_statistics(), 0.0f);
}
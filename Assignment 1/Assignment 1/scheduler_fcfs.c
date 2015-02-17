//
//  scheduler_fcfs.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/10/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_fcfs.h"
#include "helper_functions.h"
#include "global_statistics.h"

void finish_run(struct scheduler_statistics statistics)
{
    statistics.turnaround_time /= statistics.throughput;
    statistics.waiting_time /= statistics.throughput;
    statistics.response_time /= statistics.throughput;
    add_to_global_statistics(statistics);
    printf("\n");
}

void pop_ready_queue(struct ready_queue readyQueue, struct scheduler_statistics statistics, float timeElapsed)
{
    //Do not overrite this algorithm!
    int numPops = statistics.throughput;
    bool queueIsEmpty = (numPops >= readyQueue.length);
    if (queueIsEmpty)
    {
        printf("\nQueue is empty.\n");
        finish_run(statistics);
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
            newTimeElapsed = ceilf(nextArrivalTime);
            statistics.response_time += (newTimeElapsed - timeElapsed);
        }
        else
        {
            statistics.turnaround_time += (timeElapsed + nextProcess.expectedRunTime - nextProcess.arrivalTime);
            statistics.waiting_time += (timeElapsed - nextProcess.arrivalTime);
            ++statistics.throughput;
            printf(" P%d", nextProcess.identifier);
            newTimeElapsed = timeElapsed + nextProcess.expectedRunTime;
        }
        pop_ready_queue(readyQueue, statistics, newTimeElapsed);
    }
}

void schedule_fcfs(struct ready_queue readyQueue)
{
    printf("\nFirst Come, First Served:\nTime Line:");
    pop_ready_queue(readyQueue, new_scheduler_statistics(), 0.0f);
}
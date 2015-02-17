//
//  scheduler_sjf.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/11/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_sjf.h"
#include "scheduler_fcfs.h"
#include "helper_functions.h"

/*void sort_by_sjf(struct ready_queue * unsortedReadyQueue)
{
    int length = unsortedReadyQueue->length;
    struct simulated_process tempProcess;
    int i;
    for (i = 0; i < length; ++i)
    {
        struct simulated_process * iProcess = &(unsortedReadyQueue->processes[i]);
        float iJobTime = (iProcess->arrivalTime + iProcess->expectedRunTime);
        int j;
        for ( j = (i + 1); j < length; ++j)
        {
            struct simulated_process * jProcess = &(unsortedReadyQueue->processes[j]);
            float jJobTime = (jProcess->arrivalTime + jProcess->expectedRunTime);
            if (iJobTime > jJobTime)
            {
                tempProcess = *iProcess;
                *iProcess = *jProcess;
                *jProcess = tempProcess;
            }
        }
    }
}*/

void sjf_pop_ready_queue(struct ready_queue readyQueue, struct scheduler_statistics statistics, float timeElapsed)
{
    //Do not overrite this algorithm
    bool queueIsEmpty = (readyQueue.length <= 0);
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
        int i;
        int shortestJob = 0;
        for (i = 1; i < readyQueue.length; ++i)
        {
            if ((readyQueue.processes[i].arrivalTime <= timeElapsed)
                && (readyQueue.processes[i].expectedRunTime < readyQueue.processes[shortestJob].expectedRunTime))
            {
                shortestJob = i;
            }
        }
        struct simulated_process nextProcess = readyQueue.processes[shortestJob];
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
        remove_ready_queue_process(&readyQueue, shortestJob);
        sjf_pop_ready_queue(readyQueue, statistics, newTimeElapsed);
    }
}


void schedule_sjf(struct ready_queue readyQueue)
{
    printf("\nShortest Job First:\nTime Line:");
    sjf_pop_ready_queue(readyQueue, new_scheduler_statistics(), 0.0f);
}
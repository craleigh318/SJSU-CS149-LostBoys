//
//  scheduler_sjf.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/11/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_sjf.h"
#include "scheduler_fcfs.h"

void sort_by_sjf(struct ready_queue * unsortedReadyQueue)
{
    int length = unsortedReadyQueue->length;
    struct simulated_process tempProcess;
    for (int i = 0; i < length; ++i)
    {
        struct simulated_process * iProcess = &(unsortedReadyQueue->processes[i]);
        float iJobTime = (iProcess->arrivalTime + iProcess->expectedRunTime);
        for (int j = (i + 1); j < length; ++j)
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
}

void schedule_sjf(struct ready_queue readyQueue)
{
    printf("\nShortest Job First:\nTime Line:");
    sort_by_sjf(&readyQueue);
    pop_ready_queue(readyQueue, new_scheduler_statistics(), 0.0f);
}
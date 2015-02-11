//
//  scheduler_fcfs.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/10/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_fcfs.h"

void finish_run()
{
    printf("\n");
}

void pop_ready_queue(struct ready_queue readyQueue, float timeElapsed)
{
    bool queueIsEmpty = (readyQueue.length <= 0);
    if (queueIsEmpty)
    {
        printf("Queue is empty! Please enlarge queue next time.\n");
        
    }
    if (queueIsEmpty || (timeElapsed >= TIME_LIMIT))
    {
        finish_run();
    }
    else
    {
        struct simulated_process nextProcess = readyQueue.processes[0];
        ++readyQueue.processes;
        --readyQueue.length;
        float newTimeElapsed = timeElapsed + nextProcess.expectedRunTime;
        pop_ready_queue(readyQueue, newTimeElapsed);
    }
}

void schedule_fcfs(struct ready_queue readyQueue)
{
    printf("First Come, First Served:\n");
    float timeElapsed = 0.0f;
    pop_ready_queue(readyQueue, timeElapsed);
}
//
//  ready_queue.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "ready_queue.h"

struct ready_queue new_ready_queue(int length)
{
    struct ready_queue newReadyQueue =
    {
        length,
        malloc(length * sizeof(struct simulated_process))
    };
    for (int i = 0; i < length; ++i)
    {
        newReadyQueue.processes[i] = new_simulated_process();
    }
    return newReadyQueue;
}

struct ready_queue copy_ready_queue(struct ready_queue copyingReadyQueue)
{
    struct ready_queue newReadyQueue =
    {
        copyingReadyQueue.length,
        malloc(sizeof(*copyingReadyQueue.processes))
    };
    *newReadyQueue.processes = *copyingReadyQueue.processes;
    return newReadyQueue;
}

void delete_ready_queue(struct ready_queue * deletingQueue)
{
    free(deletingQueue->processes);
}
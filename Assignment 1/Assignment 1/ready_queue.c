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
    struct ready_queue newReadyQueue;
    newReadyQueue.length = length;
    struct simulated_process processes[length];
    for (int i; i < length; ++i)
    {
        processes[i] = new_simulated_process();
    }
    size_t sizeOfProcesses = sizeof(processes);
    newReadyQueue.processes = malloc(sizeOfProcesses);
    memmove(newReadyQueue.processes, &processes, sizeOfProcesses);
    return newReadyQueue;
}

void delete_ready_queue(struct ready_queue * deletingQueue)
{
    free(deletingQueue->processes);
}
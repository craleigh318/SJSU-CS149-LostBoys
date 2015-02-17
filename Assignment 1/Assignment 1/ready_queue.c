//
//  ready_queue.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "ready_queue.h"
#include "helper_functions.h"

struct ready_queue new_ready_queue(int length)
{
    struct ready_queue newReadyQueue =
    {
        length,
        {0}
    };
    int i;
    for ( i = 0; i < length; ++i) {
        newReadyQueue.processes[i] = new_simulated_process();
    }
    return newReadyQueue;
}

struct ready_queue copy_ready_queue(struct ready_queue copyingReadyQueue)
{
    return copyingReadyQueue;
}

void delete_ready_queue(struct ready_queue * deletingQueue)
{
}

void sort_ready_queue(struct ready_queue * sortingQueue)
{
    quick_sort_arrival_time(sortingQueue->processes, 0, sortingQueue->length - 1);
}

void set_ready_queue_identifier(struct ready_queue * identifierQueue)
{
    int count = 1;
    int i;
    for( i = 0; i < identifierQueue->length; i++) {
        identifierQueue->processes[i].identifier = count;
        count++;
    }
}

void add_ready_queue_process(struct ready_queue * queue, struct simulated_process addedProcess)
{
    int length = queue->length;
    queue->processes[length] = addedProcess;
    ++(queue->length);
}

struct simulated_process remove_ready_queue_process(struct ready_queue * queue, int index)
{
    struct simulated_process removedProcess = queue->processes[index];
    int oldLength = queue->length;
    int i;
    for (i = index; i < (oldLength - 1); ++i)
    {
        queue->processes[i] = queue->processes[i + 1];
    }
    --(queue->length);
    return removedProcess;
}

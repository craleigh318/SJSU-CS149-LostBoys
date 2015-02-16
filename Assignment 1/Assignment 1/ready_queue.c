//
//  ready_queue.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "ready_queue.h"
#include "helper_functions.h"

struct ready_queue new_ready_queue(int length) {
    struct ready_queue newReadyQueue = { length, malloc(
                                                        length * sizeof(struct simulated_process)) };
    for (int i = 0; i < length; ++i) {
        newReadyQueue.processes[i] = new_simulated_process();
    }
    return newReadyQueue;
}

struct ready_queue copy_ready_queue(struct ready_queue copyingReadyQueue) {
    int length = copyingReadyQueue.length;
    size_t sizeOfProcesses = length * sizeof(struct simulated_process);
    struct ready_queue newReadyQueue = { length, malloc(sizeOfProcesses) };
    memcpy(newReadyQueue.processes, copyingReadyQueue.processes,
           sizeOfProcesses);
    return newReadyQueue;
}

void delete_ready_queue(struct ready_queue * deletingQueue) {
    free(deletingQueue->processes);
}

void sort_ready_queue(struct ready_queue * sortingQueue) {
	quick_sort_arrival_time(sortingQueue->processes, 0, sortingQueue->length - 1);
}

void set_ready_queue_identifier(struct ready_queue * identifierQueue) {
    int count = 1;
    
    for(int i = 0; i < identifierQueue->length; i++) {
        identifierQueue->processes[i].identifier = count;
        count++;
    }
}

void add_ready_queue_process(struct ready_queue * queue, struct simulated_process addedProcess)
{
    struct simulated_process * oldPointer = queue->processes;
    int oldLength = queue->length;
    size_t sizeOfProcess = sizeof(struct simulated_process);
    queue->processes = malloc((oldLength + 1) * sizeOfProcess);
    memcpy(queue->processes, oldPointer, (oldLength * sizeOfProcess));
    queue->processes[oldLength] = addedProcess;
    ++queue->length;
    free(oldPointer);
}

struct simulated_process remove_ready_queue_process(struct ready_queue * queue, int index)
{
    struct simulated_process * oldPointer = queue->processes;
    int oldLength = queue->length;
    size_t sizeOfProcess = sizeof(struct simulated_process);
    queue->processes = malloc((oldLength - 1) * sizeOfProcess);
    int i = 0;
    int j = 0;
    struct simulated_process removedProcess = {0, 0.0f, 0.0f, 0};
    while (i < oldLength)
    {
        if (i == index)
        {
            removedProcess = oldPointer[i];
        }
        else
        {
            queue->processes[j] = oldPointer[i];
            ++j;
        }
        ++i;
    }
    --queue->length;
    free(oldPointer);
    return removedProcess;
}

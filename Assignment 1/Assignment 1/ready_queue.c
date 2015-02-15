//
//  ready_queue.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "ready_queue.h"

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

int partition(struct simulated_process * a, int l, int r) {
    float pivot;
    struct simulated_process t;
    int i, j;
    pivot = a[l].arrivalTime;
    i = l;
    j = r + 1;
    
    while (1) {
        do
            ++i;
        while (a[i].arrivalTime <= pivot && i <= r);
        do
            --j;
        while (a[j].arrivalTime > pivot);
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quick_sort(struct simulated_process * a, int l, int r) {
    int j;
    
    if (l < r) {
        j = partition(a, l, r);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, r);
    }
}

void sort_ready_queue(struct ready_queue * sortingQueue) {
    quick_sort(sortingQueue->processes, 0, sortingQueue->length - 1);
}

void set_ready_queue_identifier(struct ready_queue * identifierQueue) {
    int count = 1;
    
    for(int i = 0; i < identifierQueue->length; i++) {
        identifierQueue->processes[i].identifier = count;
        count++;
    }
}


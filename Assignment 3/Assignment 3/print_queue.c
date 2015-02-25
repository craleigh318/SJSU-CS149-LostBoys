//
//  print_queue.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "print_queue.h"
#include "global_variables.h"

PrintQueue new_print_queue() {
    PrintQueue newQueue = {
        0,
        0
    };
    return newQueue;
}

bool print_next_job(PrintQueue * queue) {
    int queueSize = queue->size;
    if (queueSize > 0) {
        pthread_mutex_lock(&mainPrintThreadLock);
        char * nextJob = queue->jobs[0];
        int i;
        for (i = 0; i < queueSize; ++i) {
            queue->jobs[i] = queue->jobs[i + 1];
            queueSize = queue->size;
        }
        --queue->size;
        puts(nextJob);
        pthread_mutex_unlock(&mainPrintThreadLock);
        return true;
    }
    return false;
}

void thread_loop_for_print_queue(PrintQueue * printQueue) {
    bool printQueueIsEmpty = (printQueue->size <= 0);
    if (!printQueueIsEmpty) {
        print_next_job(printQueue);
        thread_loop_for_print_queue(printQueue);
    }
}

void * thread_for_print_queue(void * params) {
    thread_loop_for_print_queue((PrintQueue *)params);
    return NULL;
}

bool add_print_job(PrintQueue * queue, char * job) {
    pthread_mutex_lock(&mainPrintThreadLock);
    int queueSize = queue->size;
    queue->jobs[queueSize] = job;
    if (queueSize <= 0) {
        pthread_create(&mainPrintThread, NULL, &thread_for_print_queue, queue);
    }
    ++queue->size;
    pthread_mutex_unlock(&mainPrintThreadLock);
    return true;
}
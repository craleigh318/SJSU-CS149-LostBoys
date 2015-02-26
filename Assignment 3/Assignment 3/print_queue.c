//
//  print_queue.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "print_queue.h"
#include "global_variables.h"

PrintQueue * new_print_queue(char * string) {
    PrintQueue * newQueue = malloc(sizeof(PrintQueue));
    newQueue->string = strdup(string);
    newQueue->tail = NULL;
    return newQueue;
}

PrintQueue * delete_print_queue(PrintQueue * queue) {
    PrintQueue * tail = queue->tail;
    free(queue->string);
    free(queue);
    return tail;
}

PrintQueue * print_next_job(PrintQueue * queue) {
    pthread_mutex_lock(&mainPrintThreadLock);
    puts(queue->string);
    PrintQueue * tail = delete_print_queue(queue);
    pthread_mutex_unlock(&mainPrintThreadLock);
    return tail;
}

void thread_loop_for_print_queue() {
    if (printQueueHead) {
        printQueueHead = print_next_job(printQueueHead);
        thread_loop_for_print_queue();
    }
}

void * thread_for_print_queue(void * params) {
    thread_loop_for_print_queue();
    return NULL;
}

bool add_print_job(PrintQueue * queue, char * job) {
    PrintQueue * tail = queue->tail;
    if (tail) {
        return add_print_job(tail, job);
    } else {
        pthread_mutex_lock(&mainPrintThreadLock);
        queue->tail = new_print_queue(job);
        pthread_mutex_unlock(&mainPrintThreadLock);
        return true;
    }
}

bool print_pq(char * job) {
    if (printQueueHead) {
        add_print_job(printQueueHead, job);
    } else {
        printQueueHead = new_print_queue(job);
        pthread_create(&mainPrintThread, NULL, &thread_for_print_queue, NULL);
    }
    return true;
}
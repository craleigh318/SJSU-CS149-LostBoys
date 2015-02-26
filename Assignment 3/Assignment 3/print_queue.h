//
//  print_queue.h
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_3__print_queue__
#define __Assignment_3__print_queue__
#include "system_headers.h"

/*
 Prints to the console.
 */
typedef struct _printQueue {
    char * string;
    struct _printQueue * tail;
} PrintQueue;

static PrintQueue * printQueueHead;

static pthread_t mainPrintThread;

static pthread_mutex_t mainPrintThreadLock;

/*
 Returns a new print queue.
 */
PrintQueue * new_print_queue(char * string);

/*
 Removes this print queue.
 Returns its tail.
 */
PrintQueue * delete_print_queue(PrintQueue * queue);

/*
 Adds a string to a print queue.
 
 Returns true if successful.
 */
bool add_print_job(PrintQueue * queue, char * job);

/*
 Adds a string to the main print queue.
 
 Returns true if successful.
 */
bool print_pq(char * job);

/*
 Prints the first-added job in a queue.
 
 Returns the tail if successful.
 */
PrintQueue * print_next_job(PrintQueue * queue);

/*
 Entry point for the print queue thread.
 */
void * thread_for_print_queue(void * params);

#endif /* defined(__Assignment_3__print_queue__) */

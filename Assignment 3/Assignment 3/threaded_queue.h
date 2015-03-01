//
//  threaded_queue.h
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Queues_for_C__threaded_queue__
#define __Queues_for_C__threaded_queue__
#include "queue.h"
#include <pthread.h>

/*
 A queue that synchronizes with multithreading.
 */
typedef struct _threadedQueue {
    /*
     The queue.
     */
    Queue queue;
    
    /*
     Locks when the queue is in use.
     */
    pthread_mutex_t mutex;
    
} ThreadedQueue;

/*
 Creates a new threaded queue.
 */
ThreadedQueue new_threaded_queue();

/*
 Returns true if this threaded queue is empty.
 */
bool threaded_queue_is_empty(ThreadedQueue * threadedQueue);

/*
 Adds the specified datum to the specified threaded queue.
 */
void add_to_threaded_queue(ThreadedQueue * threadedQueue, void * datum);

/*
 Removes and returns the head of this threaded queue.
 */
void * remove_from_threaded_queue(ThreadedQueue * threadedQueue);

#endif /* defined(__Queues_for_C__threaded_queue__) */

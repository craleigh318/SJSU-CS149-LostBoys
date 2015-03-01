//
//  threaded_queue.c
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "threaded_queue.h"

// Creates and returns a new threaded queue
ThreadedQueue new_threaded_queue()
{
    ThreadedQueue newThreadedQueue;
    newThreadedQueue.queue = new_queue();
    return newThreadedQueue;
}

// Checks to see if the given threadQueue is empty
bool threaded_queue_is_empty(ThreadedQueue * threadedQueue) {
    return queue_is_empty(&threadedQueue->queue);
}
// Add datum (information of student) into the threadedQueue
void add_to_threaded_queue(ThreadedQueue * threadedQueue, void * datum) {
    pthread_mutex_lock(&threadedQueue->mutex);
    add_to_queue(&threadedQueue->queue, datum);
    pthread_mutex_unlock(&threadedQueue->mutex);
}

// Get the head by removing it from the queue 
void * remove_from_threaded_queue(ThreadedQueue * threadedQueue) {
    pthread_mutex_lock(&threadedQueue->mutex);
    void * returnDatum = remove_from_queue(&threadedQueue->queue);
    pthread_mutex_unlock(&threadedQueue->mutex);
    return returnDatum;
}
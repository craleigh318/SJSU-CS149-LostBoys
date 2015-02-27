//
//  threaded_queue.c
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "threaded_queue.h"

ThreadedQueue new_threaded_queue() {
    ThreadedQueue newThreadedQueue;
    newThreadedQueue.queue = new_queue();
    return newThreadedQueue;
}

bool threaded_queue_is_empty(ThreadedQueue * threadedQueue) {
    return queue_is_empty(&threadedQueue->queue);
}

void add_to_threaded_queue(ThreadedQueue * threadedQueue, void * datum) {
    pthread_mutex_lock(&threadedQueue->mutex);
    add_to_queue(&threadedQueue->queue, datum);
    pthread_mutex_unlock(&threadedQueue->mutex);
}

void * remove_from_threaded_queue(ThreadedQueue * threadedQueue) {
    pthread_mutex_lock(&threadedQueue->mutex);
    void * returnDatum = remove_from_queue(&threadedQueue->queue);
    pthread_mutex_unlock(&threadedQueue->mutex);
    return returnDatum;
}
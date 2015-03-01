//
//  queue.c
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "queue.h"

Queue new_queue() {
    Queue newQueue; // A linked list
    newQueue.head = NULL; // Set the head/front of the queue to null
    newQueue.tail = NULL; // Set the tail/back of the queue to null
    return newQueue; // return an empty queue
}

bool queue_is_empty(Queue * queue) // Looks at the given queue passed in
{
    return !queue->head; // If head is not null , therefore there is a head and returns true
}

void add_to_queue(Queue * queue, void * datum) // Datum , the element to be added into the passed in queue
    {
    QueueElement * newTail = new_queue_element(datum); // Add the element into the tail of the queue
    if (queue_is_empty(queue)) // If the queue is empty ,
    {
        queue->head = newTail; // Datum becomes the head of the queue
    } else {
        queue->tail->next = newTail; // Datum gets added at the end of the queue
    }
    queue->tail = newTail;
}

void * remove_from_queue(Queue * queue) // remove element from a given queue
{
    QueueElement * oldHead = queue->head; // Gets the queue's head
    void * returnDatum = oldHead->datum; // Get the queue's head information
    queue->head = oldHead->next; // the element before the head becomes the next head
    delete_queue_element(oldHead); // Get rid of the head we had originally
    if (queue_is_empty(queue)) {
        queue->tail = NULL; // If there is no head, the tail & head is null
    }
    return returnDatum; // ????
}
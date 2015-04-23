//
//  Child.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Child.h"

void deleteChild(Child * deletingChild) {
    free(deletingChild);
}

void * runChild(void * params) {
    Child * child = params;
    deleteChild(child);
    return NULL;
}

void newChild(int id, int * pipe) {
    Child * newChild = malloc(sizeof(Child));
    newChild->id = id;
    newChild->pipe = pipe;
    newChild->numMessages = 0;
    pthread_create(&(newChild->thread), NULL, runChild, newChild);
}
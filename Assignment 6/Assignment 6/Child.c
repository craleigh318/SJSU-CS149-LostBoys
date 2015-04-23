//
//  Child.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Child.h"

void runChild(Child * child) {
    ++(child->numMessages);
    printf("Child %d message %d", child->id, child->numMessages);
}

Child newChild(int id, int * pipe) {
    Child newChild;
    newChild.id = id;
    newChild.pipe = pipe;
    newChild.numMessages = 0;
    return newChild;
}
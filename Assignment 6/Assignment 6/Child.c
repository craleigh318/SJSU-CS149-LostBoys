//
//  Child.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Child.h"

Child newChild(int id, int * pipe, bool input) {
    Child newChild;
    newChild.id = id;
    newChild.pipe = pipe;
    newChild.numMessages = 0;
    newChild.input = input;
    return newChild;
}

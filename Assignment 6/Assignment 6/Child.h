//
//  Child.h
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_6__Child__
#define __Assignment_6__Child__
#include "SystemHeaders.h"

typedef struct _Child {
    /*
     A unique ID for this child.
     */
    int id;
    
    /*
     A two-integer array, for reading and writing.
     */
    int * pipe;
    
    /*
     The number of messages that this child has written.
     */
    int numMessages;

    /*
     Determines if the child is a default child or able to take in input
     false = default
     true = allows input
     */
    bool input;
} Child;

Child newChild(int id, int * pipe, bool input);

#endif /* defined(__Assignment_6__Child__) */

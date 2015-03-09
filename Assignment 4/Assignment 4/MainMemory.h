//
//  MainMemory.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__MainMemory__
#define __Assignment_4__MainMemory__
#include "SystemHeaders.h"
#include "Process.h"

/*
 Contains 100 MB to create proceseses.
 */
typedef struct {
    
    /*
     Amount of memory left, in MB.
     */
    int availableMemory;
    
} MainMemory;

static const int maxMainMemorySize = 100;

/*
 Constructs and returns a new block of main memory.
 */
MainMemory newMainMemory();

/*
 Creates and returns a new process from this memory.
 */
Process getNewProcessFromMemory(MainMemory * mainMemory);

#endif /* defined(__Assignment_4__MainMemory__) */

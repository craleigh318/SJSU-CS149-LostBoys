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
#define MAIN_MEMORY_SIZE 100

/*
 Constructs and returns a new block of main memory.
 A block of main memory is an array of 100 process pointers.
 */
Process ** newMainMemory();

/*
 Deletes this block of main memory.
 */
void deleteMainMemory(Process ** mainMemory);

/*
 Prints this block of main memory.
 */
void printMainMemory(Process ** mainMemory);

#endif /* defined(__Assignment_4__MainMemory__) */

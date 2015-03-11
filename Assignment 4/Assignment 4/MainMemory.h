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



/*
 Contains 100 MB to create proceseses.
 */
typedef struct {
    
    /*
     100 MB of memory.
     Each MB of memory points to the process using it.
     Available MBs point to null.
     */
    Process * memory[MAIN_MEMORY_SIZE];
    
} MainMemory;



/*
 Returns true if the specified process can be added to the main memory at the specified address.
 If a 5 MB process is added to 10, then blocks 10 through 15 will be occupied.
 */
bool processWillFit(MainMemory * mainMemory, Process * process, int location);

/*
 Adds the specified process to the main memory at the specified address.
 If a 5 MB process is added to 10, then blocks 10 through 15 will be occupied.
 Returns true if successful.
 */
bool addProcessToMainMemory(MainMemory * mainMemory, Process * process, int location);

#endif /* defined(__Assignment_4__MainMemory__) */

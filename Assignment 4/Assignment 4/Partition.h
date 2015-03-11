//
//  Partition.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/10/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__Partition__
#define __Assignment_4__Partition__
#include "SystemHeaders.h"
#include "Process.h"
#include "MainMemory.h"

/*
 A block of continuous memory owned by one process (or lack thereof).
 */
typedef struct _Partition {
    Process ** mainMemory;
    int firstMB;
    int finalMB;
} Partition;

/*
 New partition.
 */
Partition * newPartition(Process ** mainMemory, int firstMB, int finalMB);

/*
 Deletes partition.
 */
void deletePartition(Partition * partition);

/*
 Returns a vector of any unused partitions in this memory.
 */
std::vector<Partition *> getHolesInMemory(Process ** mainMemory);

/*
 Returns the process running on this partition.
 Returns null if this partition is available.
 */
Process * getProcessFromPartition(Partition * partition);

/*
 Returns the size of this partition, in MB.
 */
int getPartitionSize(Partition * partition);

/*
 Adds the specified process to the hole.
 A hole is an unoccupied partition.
 Returns true if successful.
 */
bool addProcessToHole(Partition * hole, Process * process);

#endif /* defined(__Assignment_4__Partition__) */

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

/*
 A block of continuous memory owned by one process (or lack thereof).
 */
typedef struct _Partition Partition;

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
 Returns a new partition for the process if successful.
 Returns null if unsuccessful.
 */
Partition * addProcessToHole(Partition * hole, Process * process);

#endif /* defined(__Assignment_4__Partition__) */

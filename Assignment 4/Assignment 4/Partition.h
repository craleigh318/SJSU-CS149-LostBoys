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
class Partition {
    
public:
    /*
     Returns a vector of any unused partitions in this memory.
     */
    static std::vector<Partition> getHolesInMemory(MainMemory * mainMemory);
    
    /*
     New partition.
     */
    Partition(MainMemory * mainMemory, int firstMB, int finalMB);
    
    /*
     Returns the process running on this partition.
     Returns null if this partition is available.
     */
    const Process * const getProcess();
    
    /*
     Returns the size of this partition, in MB.
     */
    int getSize();
    
    /*
     Adds the specified process to the hole.
     A hole is an unoccupied partition.
     Returns true if successful.
     */
    bool addProcess(Process * process);
    
private:
    MainMemory * mainMemory;
    
    int firstMB;
    
    int finalMB;
};

#endif /* defined(__Assignment_4__Partition__) */

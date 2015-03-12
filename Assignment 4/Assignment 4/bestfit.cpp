//
//  bestfit.c
//  Assignment 4
//
//  Created by Will Chan on 3/10/15.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "bestfit.h"

bool runBestFit()
{
    Process **memory = newMainMemory(); // Gets a new block of main memory as an array of 100 process pointers 
    std::vector<Partition *> holes = getHolesInMemory(memory);  // Returns a vector that has found holes in the main memory memory
    int startOfVector = 0, startOfMain = 0; // the starting index of Vector & Main Memory
    while(startOfMain < 100) // while we're at the begining of the main memory to begin adding in process
    {
        Process *process = newProcess(); // We first create a randomly generated process and store it into *process
        startOfMain += getProcessSize(process); // Then we get the process' size and increment the index of the main memory
        // every index before the index got updated is changed to 1 MB
        
        while(startOfVector < holes.size()) // Start adding processes in the vector 
        {
            if ( holes.at(startOfVector) == NULL && startOfVector < getProcessSize(process) ) // if the vector at that index is null ( or  0 )
            {
                holes.at(startOfVector); // Adds that process into the array of that index
                startOfVector++;  // moves the index to the start 
            }
        }
    }
    return false;
}

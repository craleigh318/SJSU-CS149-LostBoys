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
    MainMemory memory; // Gets a new block of main memory as an array of 100 process pointers
    std::vector<Partition> holes = Partition::getHolesInMemory(&memory);  // Returns a vector that has found holes in the main memory
    int startOfVector = 0, startOfMain = 0; // the starting index of Vector & Main Memory
    while(startOfMain < 100) // while we're at the begining of the main memory to begin adding in process
    {
        Process process; // We first create a randomly generated process and store it into *process
        while(startOfVector < holes.size()) // Start adding processes in the vector 
        {
            if (startOfVector < process.getSize() ) // if the vector at that index is null ( or  0 )
            {
                bool added = holes.at(startOfVector).addProcess(&process);
                startOfVector++;  // moves the index to the start
                startOfMain++; // moves the index of the start of main to how many MBs the process has
            }
        }
    }
    return false;
}

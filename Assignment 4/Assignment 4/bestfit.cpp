//
//  bestfit.c
//  Assignment 4
//
//  Created by Will Chan on 3/10/15.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "bestfit.h"
#define MAIN_MEMORY_SIZE 100

/*bool runBestFit()
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
}*/


bool startBestFit(MainMemory * memory, Process* process) {
	std::vector<Partition> holes = Partition::getHolesInMemory(memory);
    if (holes.size() <= 0) {
        return false;
    }
	int holeSize = 0;
	int minSize = MAIN_MEMORY_SIZE;
	int minindex = 0;
	for (int i=0; i < holes.size(); i++) {
			holeSize = holes.at(i).getSize();
			if(holeSize < minSize && process->getSize() <= holeSize) {
				minSize = holeSize;
				minindex = i;
			}
		}

    return holes.at(minindex).addProcess(process);
}



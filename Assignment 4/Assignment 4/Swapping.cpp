//
//  Swapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Swapping.h"

void swappingStart() {
    //MainMemory mainMemory;
    Process * exampleProcess = newProcess();
    std::cout << "Example Process:\nSize:\t\t" << getProcessSize(exampleProcess)
    << " MB\nDuration:\t" << getProcessDuration(exampleProcess) << " s\n";
    Process ** exampleMemory = newMainMemory();
    std::vector<Partition *> holes = getHolesInMemory(exampleMemory);
    addProcessToHole(holes.at(0), exampleProcess);
    printMainMemory(exampleMemory);
    std::cout << "Hole Size: " << getPartitionSize(holes.at(0)) << '\n';
    deleteProcess(exampleProcess);
    deleteMainMemory(exampleMemory);
}
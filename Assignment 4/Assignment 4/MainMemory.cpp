//
//  MainMemory.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "MainMemory.h"

MainMemory::MainMemory() :
availableMemory(size)
{
}

Process MainMemory::getNewProcess() {
    int newProcessSize = Process::getRandomSize(size);
    int newProcessDuration = Process::getRandomDuration(size);
    Process newProcess(newProcessSize, newProcessDuration);
    availableMemory -= newProcessSize;
    return newProcess;
}
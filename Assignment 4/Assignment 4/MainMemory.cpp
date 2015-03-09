//
//  MainMemory.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "MainMemory.h"

MainMemory newMainMemory() {
    MainMemory newMainMemory;
    newMainMemory.availableMemory = maxMainMemorySize;
    return newMainMemory;
}

Process getNewProcessFromMemory(MainMemory * mainMemory) {
    int newProcessSize = getRandomSize(maxMainMemorySize);
    int newProcessDuration = getRandomDuration(maxMainMemorySize);
    Process createdProcess = newProcess(newProcessSize, newProcessDuration);
    mainMemory->availableMemory -= newProcessSize;
    return createdProcess;
}
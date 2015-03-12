//
//  Partition.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/10/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Partition.h"

Partition::Partition(MainMemory * mainMemory, int firstMB, int finalMB) :
mainMemory(mainMemory),
firstMB(firstMB),
finalMB(finalMB)
{
}

std::vector<Partition> Partition::getHolesInMemory(MainMemory * mainMemory) {
    std::vector<Partition> memoryHoles;
    Partition * currentPartition = NULL;
    int i;
    // For each element in main memory.
    for (i = 0; i < MAIN_MEMORY_SIZE; ++i) {
        // If this MB is in use.
        if (mainMemory->getMB(i)) {
            // If a hole was being recorded, then it must stop and be added to the vetor.
            if (currentPartition) {
                memoryHoles.push_back(*currentPartition);
                delete currentPartition;
                currentPartition = NULL;
            }
        }
        // Else, this MB is part of a hole.
        else {
            // If this is not the first MB of the hole.
            if (currentPartition) {
                currentPartition->finalMB = i;
            }
            // Else, this is the first MB of the hole.
            else {
                currentPartition = new Partition(mainMemory, i, i);
            }
        }
    }
    if (currentPartition) {
        memoryHoles.push_back(*currentPartition);
        delete currentPartition;
    }
    return memoryHoles;
}

const Process * const Partition::getProcess() {
    return mainMemory->getMB(firstMB);
}

int Partition::getSize() {
    return finalMB - firstMB + 1;
}

bool Partition::addProcess(Process * process) {
    if (firstMB > finalMB) {
        return false;
    }
    int i;
    for (i = firstMB; i < (process->getSize() + firstMB); ++i) {
        mainMemory->setMB(i, process);
    }
    firstMB = i;
    return true;
}

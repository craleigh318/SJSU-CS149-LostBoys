//
//  Partition.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/10/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Partition.h"

Partition * newPartition(MainMemory * mainMemory, int firstMB, int finalMB) {
    Partition * newPartition = (Partition *)malloc(sizeof(Partition));
    newPartition->mainMemory = mainMemory;
    newPartition->firstMB = firstMB;
    newPartition->finalMB = finalMB;
    return newPartition;
}

void deletePartition(Partition * partition) {
    free(partition);
}

std::vector<Partition *> getHolesInMemory(MainMemory * mainMemory) {
    std::vector<Partition *> memoryHoles;
    Partition * currentPartition = NULL;
    int i;
    // For each element in main memory.
    for (i = 0; i < MAIN_MEMORY_SIZE; ++i) {
        // If this MB is in use.
        if (mainMemory->getMB(i)) {
            // If a hole was being recorded, then it must stop and be added to the vetor.
            if (currentPartition) {
                memoryHoles.push_back(currentPartition);
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
                currentPartition = newPartition(mainMemory, i, i);
            }
        }
    }
    if (currentPartition) {
        memoryHoles.push_back(currentPartition);
    }
    return memoryHoles;
}

const Process * const getProcessFromPartition(Partition * partition) {
    return partition->mainMemory->getMB(partition->firstMB);
}

int getPartitionSize(Partition * partition) {
    return partition->finalMB - partition->firstMB + 1;
}

bool addProcessToHole(Partition * hole, Process * process) {
    int i;
    for (i = hole->firstMB; i < (process->getSize() + hole->firstMB); ++i) {
        hole->mainMemory->setMB(i, process);
    }
    hole->firstMB = i;
    return true;
}

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

std::vector<Partition> Partition::getPartitionsInMemory(MainMemory * mainMemory) {
    std::vector<Partition> partitions;
    Partition * currentPartition = NULL;
    int i;
    // For each element in main memory.
    for (i = 0; i < MAIN_MEMORY_SIZE; ++i) {
        // If a partition is being recorded.
        if (currentPartition) {
            // If this is the same process, keep adding to it.
            if (mainMemory->getMB(i - 1) == mainMemory->getMB(i)) {
                currentPartition->finalMB = i;
            }
            // Else, finish the partition.
            else {
                partitions.push_back(*currentPartition);
                delete currentPartition;
                currentPartition = new Partition(mainMemory, i, i);
            }
        }
        // Else, a partition is not being recorded.
        else {
            currentPartition = new Partition(mainMemory, i, i);
        }
    }
    if (currentPartition) {
        partitions.push_back(*currentPartition);
        delete currentPartition;
    }
    return partitions;
}

std::vector<Partition> Partition::getHolesInMemory(MainMemory * mainMemory) {
    std::vector<Partition> memoryHoles;
    std::vector<Partition> partitions = getPartitionsInMemory(mainMemory);
    int i;
    for (i = 0; i < partitions.size(); ++i) {
        Partition currentPartition = partitions.at(i);
        if (!currentPartition.getProcess()) {
            memoryHoles.push_back(currentPartition);
        }
    }
    return memoryHoles;
}

std::vector<Partition> Partition::getPartitionsInMemoryWithProcesses(MainMemory * mainMemory) {
    std::vector<Partition> processes;
    std::vector<Partition> partitions = getPartitionsInMemory(mainMemory);
    int i;
    for (i = 0; i < partitions.size(); ++i) {
        Partition currentPartition = partitions.at(i);
        if (currentPartition.getProcess()) {
            processes.push_back(currentPartition);
        }
    }
    return processes;
}

Process * Partition::getProcess() {
    return mainMemory->getMB(firstMB);
}

int Partition::getSize() {
    return finalMB - firstMB + 1;
}


int Partition::getFirstMB() {
    return firstMB;
}

int Partition::getFinalMB() {
    return finalMB;
}

bool Partition::addProcess(Process * process) {
    if (firstMB > finalMB) {
        return false;
    }
    if ((firstMB + process->getSize()) > finalMB) {
        return false;
    }
    int i;
    for (i = firstMB; i < (process->getSize() + firstMB); ++i) {
        mainMemory->setMB(i, process);
    }
    firstMB = i;
    return true;
}

bool Partition::movePartition(Partition* partition) {
	int i;
	int partitionSize = partition->getSize();
    for (i = firstMB; i < (partitionSize + firstMB); ++i) {
        mainMemory->setMB(i, partition->getProcess());
    }
    partition->firstMB = firstMB;
    partition->finalMB = firstMB + partitionSize;
    firstMB = i;

    for (i = firstMB; i < (partitionSize + finalMB + 1); ++i) {
        mainMemory->setMB(i, NULL);
    }
    finalMB = i;

    return true;
}

bool Partition::removeProcess() {
    Process * process = getProcess();
    if (firstMB > finalMB) {
        return false;
    }
    int i;
    for (i = firstMB; i < (process->getSize() + firstMB); ++i) {
        mainMemory->setMB(i, NULL);
    }
    firstMB = i;
    return true;
}

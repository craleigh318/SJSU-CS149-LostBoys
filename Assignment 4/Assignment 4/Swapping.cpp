//
//  Swapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Swapping.h"

bool CompareProcesses::operator()(Process * process1, Process * process2) {
    return (process1->getArrivalTime() > process2->getArrivalTime());
}

void swapWithAlgorithm(std::priority_queue<Process *, std::vector<Process *>, CompareProcesses> processQueue,
                       bool (* algorithm)(MainMemory * memory, Process * process)) {
    MainMemory memory;
    int currentTime;
    for (currentTime = 0; currentTime < TIME_LIMIT; ++currentTime) {
        Process * nextProcess = processQueue.top();
        if (nextProcess->getArrivalTime() <= currentTime) {
            processQueue.pop();
            algorithm(&memory, nextProcess);
        }
        std::cout << "Second " << currentTime << '\n';
        memory.print();
        std::cout << '\n';
    }
}

void swappingStart() {
    std::cout << "Swapping:\n";
    std::priority_queue<Process *, std::vector<Process *>, CompareProcesses> orderedProcesses;
    const int queueSize = 26;
    int i;
    for (i = 0; i < queueSize; ++i) {
        Process * newProcess = new Process();
        newProcess->print();
        std::cout << '\n';
        orderedProcesses.push(newProcess);
    }
    // Put your algorithms here.
    std::cout << "First Fit:\n";
    swapWithAlgorithm(orderedProcesses, &startFirstFitSwapping);

    std::cout << "Next Fit:\n";
    swapWithAlgorithm(orderedProcesses, &startNextFit);

    std::cout << "Worst Fit:\n";
        swapWithAlgorithm(orderedProcesses, &startWorstFit);
    // Deleting processes when done.
    for (i = 0; i < queueSize; ++i) {
        Process * nextProcess = orderedProcesses.top();
        delete nextProcess;
        orderedProcesses.pop();
    }
}

//
//  Swapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Swapping.h"

void swapWithAlgorithm(std::priority_queue<Process *> processQueue,
                       void (* algorithm)(MainMemory * memory, Process * process)) {
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
    std::priority_queue<Process *> orderedProcesses;
    const int queueSize = 26;
    int i;
    for (i = 0; i < queueSize; ++i) {
        Process * newProcess = new Process();
        newProcess->print();
        orderedProcesses.push(newProcess);
    }
    std::cout << "First Fit:\n";
    swapWithAlgorithm(orderedProcesses, &startFirstFitSwapping);
    for (i = 0; i < queueSize; ++i) {
        Process * nextProcess = orderedProcesses.top();
        delete nextProcess;
        orderedProcesses.pop();
    }
}

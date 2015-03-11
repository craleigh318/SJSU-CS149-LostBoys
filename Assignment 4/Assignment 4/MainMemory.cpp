//
//  MainMemory.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "MainMemory.h"

Process ** newMainMemory() {
    Process ** newMainMemory = (Process **)calloc(MAIN_MEMORY_SIZE, sizeof(Process *));
    return newMainMemory;
}

void deleteMainMemory(Process ** mainMemory) {
    free(mainMemory);
}

void printMainMemory(Process ** mainMemory) {
    int i;
    const int numRows = 5;
    const int numColumns = 20;
    for (i = 0; i < numRows; ++i) {
        int j;
        for (j = 0; j < numColumns; ++j) {
            int index = (numRows * i) + j;
            Process * currentProcess = mainMemory[index];
            if (currentProcess) {
                std::cout << getProcessName(currentProcess);
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}

bool processWillFit(MainMemory * mainMemory, Process * process, int location) {
    int finalAddress = location + getProcessSize(process) - 1;
    if (finalAddress >= MAIN_MEMORY_SIZE) {
        return false;
    }
    int currentAddress;
    for (currentAddress = location; currentAddress <= finalAddress; ++currentAddress) {
        Process * processPointer = mainMemory->memory[currentAddress];
        // If memory block is occupied.
        if (processPointer) {
            return false;
        }
    }
    return true;
}

bool addProcessToMainMemory(MainMemory * mainMemory, Process * process, int location) {
    if (!processWillFit(mainMemory, process, location)) {
        return false;
    }
    int currentAddress;
    int finalAddress = location + getProcessSize(process) - 1;
    for (currentAddress = location; currentAddress <= finalAddress; ++currentAddress) {
        mainMemory->memory[currentAddress] = process;
    }
    return true;
}
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
            int index = (numColumns * i) + j;
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
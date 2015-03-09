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
    return newMainMemory;
}

bool addProcessToMainMemory(MainMemory * mainMemory, Process * process, int location) {
    int finalAddress = location + process->size;
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
    for (currentAddress = location; currentAddress <= finalAddress; ++currentAddress) {
        mainMemory->memory[currentAddress] = process;
    }
    return true;
}
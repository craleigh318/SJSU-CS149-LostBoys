//
//  Swapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Swapping.h"

void swappingStart() {
    MainMemory mainMemory;
    Process exampleProcess = getNewProcessFromMemory(&mainMemory);
    std::cout << "Example Process:\nSize:\t\t" << exampleProcess.size
    << " MB\nDuration:\t" << exampleProcess.duration << " s\n";
}
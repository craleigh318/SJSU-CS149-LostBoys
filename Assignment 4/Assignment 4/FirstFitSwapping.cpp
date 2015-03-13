//
//  FirstFitSwapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/12/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "FirstFitSwapping.h"

bool startFirstFitSwapping(MainMemory * memory, Process * process) {
    std::vector<Partition> holes = Partition::getHolesInMemory(memory);
    int i;
    for (i = 0; i < holes.size(); ++i) {
        int processSize = process->getSize();
        Partition & thisHole = holes.at(i);
        int holeSize = thisHole.getSize();
        if (processSize <= holeSize) {
            thisHole.addProcess(process);
            return true;
        }
    }
    return false;
}
//
//  MainMemory.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "MainMemory.h"

MainMemory::MainMemory() :
mbs()
{
}

const Process * MainMemory::getMB(int mb) {
    return mbs[mb];
}

void MainMemory::setMB(int mb, Process * value) {
    mbs[mb] = value;
}

void MainMemory::print() {
    int i;
    const int numRows = 5;
    const int numColumns = 20;
    for (i = 0; i < numRows; ++i) {
        int j;
        for (j = 0; j < numColumns; ++j) {
            int index = (numColumns * i) + j;
            Process * currentProcess = mbs[index];
            if (currentProcess) {
                std::cout << currentProcess->getName();
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}
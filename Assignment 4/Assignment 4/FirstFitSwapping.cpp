//
//  FirstFitSwapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/12/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "FirstFitSwapping.h"

void startFirstFitSwapping() {
    MainMemory mainMemory;
    Process process1;
    Process process2;
    mainMemory.print();
    std::cout << '\n';
    std::vector<Partition> holes = Partition::getHolesInMemory(&mainMemory);
    holes.at(0).addProcess(&process1);
    mainMemory.print();
    std::cout << '\n';
    std::vector<Partition> holes2 = Partition::getHolesInMemory(&mainMemory);
    holes2.at(0).addProcess(&process2);
    mainMemory.print();
    std::cout << '\n';
}
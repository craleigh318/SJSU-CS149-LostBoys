//
//  main.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "SystemHeaders.h"
#include "MainMemory.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned int)time(NULL));
    std::cout << "Hello, World!\n";
    MainMemory mainMemory;
    Process exampleProcess = getNewProcessFromMemory(&mainMemory);
    std::cout << "Example Process:\nSize:\t\t" << exampleProcess.size
    << " MB\nDuration:\t" << exampleProcess.duration << " s\n";
    return 0;
}

//
//  MainMemory.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__MainMemory__
#define __Assignment_4__MainMemory__
#include "SystemHeaders.h"
#include "Process.h"

/*
 Contains 100 MB to create proceseses.
 */
class MainMemory {
    
public:
    static const int size = 100;
    
    /*
     Constructor.
     */
    MainMemory();
    
    /*
     Creates and returns a new process from this memory.
     */
    Process getNewProcess();
    
private:
    int availableMemory;
};

#endif /* defined(__Assignment_4__MainMemory__) */

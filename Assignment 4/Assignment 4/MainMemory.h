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
#define MAIN_MEMORY_SIZE 100

class MainMemory {
    
public:
    /*
     Constructs a new block of main memory.
     A block of main memory is an array of 100 process pointers.
     */
    MainMemory();
    
    /*
     Returns the process using this MB.
     */
    const Process * const getMB(int mb);
    
    /*
     Assigns this MB to a process
     */
    void setMB(int mb, Process * value);
    
    /*
     Prints this block of main memory.
     */
    void print();
    
private:
    Process * mbs[MAIN_MEMORY_SIZE];
};

#endif /* defined(__Assignment_4__MainMemory__) */

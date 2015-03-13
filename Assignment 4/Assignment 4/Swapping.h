//
//  Swapping.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__Swapping__
#define __Assignment_4__Swapping__
#include "SystemHeaders.h"
#include "MainMemory.h"
#include "Partition.h"
#include "NextFitSwapping.h"
#include "FirstFitSwapping.h"
#include "bestfit.h"
#define RUNTIME 10

/*
 Overrides comparison method.
 */
class CompareProcesses {
public:
    bool operator()(Process * process1, Process * process2);
};

/*
 Memory swaps using the specified algorithm.
 */
void swapWithAlgorithm(std::priority_queue<Process *, std::vector<Process *>, CompareProcesses> processQueue,
                       void (* algorithm)(MainMemory * memory, Process * process));

/*
 Starts the swapping part of the assignment.
 */
void swappingStart();

#endif /* defined(__Assignment_4__Swapping__) */

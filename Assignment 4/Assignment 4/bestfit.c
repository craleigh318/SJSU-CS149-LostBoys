//
//  bestfit.c
//  Assignment 4
//
//  Created by Will Chan on 3/10/15.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "bestfit.h"

// Best Fit - search the Linked Lists of memory segments for the smallest hole where the process will fit
// Slower: longer search
// Rsult: More wasted memory
// Fills memory with tiny useless holes

void runBestFit()
{
    Process **mem = newMainMemory(); // A block of main memory is an array of 100 process pointers
    Process *process = newProcess(); // A randomly simulated process with size and duration
    
}
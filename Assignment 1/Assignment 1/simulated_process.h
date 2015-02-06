//
//  simulated_process.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/05/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__simulated_process__
#define __Assignment_1__simulated_process__
#include "system_headers.h"

struct simulated_process
{
    float arrivalTime;
    float expectedRunTime;
    int priority;
};

struct simulated_process new_simulated_process();

#endif /* defined(__Assignment_1__simulated_process__) */

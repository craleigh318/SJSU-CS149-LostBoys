//
//  simulated_process.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/05/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "simulated_process.h"
#include "helper_functions.h"

struct simulated_process new_simulated_process(int identifier)
{
    struct simulated_process newSimulatedProcess =
    {
    	identifier,
        getRandomFloat(0.0f, 99.0f),
        getRandomFloat(0.1f, 10.0f),
        getRandomInt(1, 4)
    };
    return newSimulatedProcess;
}

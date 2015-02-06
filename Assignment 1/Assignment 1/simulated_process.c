//
//  simulated_process.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/05/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "simulated_process.h"

float getRandomFloat(float minimum, float maximum)
{
    float floatWithinOne = ((float)rand()) / ((float)RAND_MAX);
    return (maximum * floatWithinOne) - (minimum * floatWithinOne) + minimum;
}

int getRandomInt(int minimum, int maximum)
{
    return (rand() % (maximum - minimum + 1)) + minimum;
}

struct simulated_process new_simulated_process()
{
    struct simulated_process newSimulatedProcess;
    newSimulatedProcess.arrivalTime = getRandomFloat(0.0f, 99.0f);
    newSimulatedProcess.expectedRunTime = getRandomFloat(0.1f, 10.0f);
    newSimulatedProcess.priority = getRandomInt(1, 4);
    return newSimulatedProcess;
}
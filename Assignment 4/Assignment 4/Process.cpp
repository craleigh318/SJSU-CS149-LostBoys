//
//  Process.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Process.h"

Process newProcess(int size, int duration) {
    Process newProcess;
    newProcess.size = size;
    newProcess.duration = duration;
    return newProcess;
}

int getRandomIntFromArray(const int * array, const int arraySize, int max) {
    int i;
    int numSizesWithinMax = 0;
    for (i = 0; i < arraySize; ++i) {
        if (allowedSizes[i] <= max) {
            ++numSizesWithinMax;
        } else {
            break;
        }
    }
    int randomInt = rand() % numSizesWithinMax;
    int returnValue = array[randomInt];
    return returnValue;
}

int getRandomSize(int max) {
    return getRandomIntFromArray(allowedSizes, 4, max);
}

int getRandomDuration(int max) {
    return getRandomIntFromArray(allowedDurations, 5, max);
}


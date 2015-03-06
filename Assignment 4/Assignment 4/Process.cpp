//
//  Process.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Process.h"

const int Process::allowedSizes[] = {
    5,
    11,
    17,
    31
};

const int Process::allowedDurations[] = {
    1,
    2,
    3,
    4,
    5
};

int Process::getRandomSize(int max) {
    return getRandomIntFromArray(allowedSizes, 4, max);
}

int Process::getRandomDuration(int max) {
    return getRandomIntFromArray(allowedDurations, 5, max);
}

Process::Process(int size, int duration) :
size(size),
duration(duration)
{
}

int Process::getSize() {
    return size;
}

int Process::getDuration() {
    return duration;
}

int Process::getRandomIntFromArray(const int array[], const int arraySize, int max) {
    int i;
    int numSizesWithinMax = 0;
    for (i = 0; i < arraySize; ++i) {
        if (allowedSizes[i]) {
            ++numSizesWithinMax;
        } else {
            break;
        }
    }
    int randomInt = rand() % numSizesWithinMax;
    int returnValue = array[randomInt];
    return returnValue;
}
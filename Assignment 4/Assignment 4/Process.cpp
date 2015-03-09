//
//  Process.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Process.h"

Process newProcess() {
    Process newProcess;
    newProcess.size = getRandomSize();
    newProcess.duration = getRandomDuration();
    return newProcess;
}

int getRandomIntFromArray(const int * array, const int arraySize) {
    int randomInt = rand() % arraySize;
    int returnValue = array[randomInt];
    return returnValue;
}

int getRandomSize() {
    return getRandomIntFromArray(allowedSizes, 4);
}

int getRandomDuration() {
    return getRandomIntFromArray(allowedDurations, 5);
}


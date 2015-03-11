//
//  Process.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Process.h"

static const int allowedSizes[] = {
    5,
    11,
    17,
    31
};

static const int allowedDurations[] = {
    1,
    2,
    3,
    4,
    5
};

static char currentLetter = 'A';

/*
 Returns a random int from the specified array.
 */
int getRandomIntFromArray(const int * array, const int arraySize) {
    int randomInt = rand() % arraySize;
    int returnValue = array[randomInt];
    return returnValue;
}

/*
 Returns a random size less than or equal to the specified max.
 */
int getRandomSize() {
    return getRandomIntFromArray(allowedSizes, 4);
}

/*
 Returns a random duration less than or equal to the specified max.
 */
int getRandomDuration() {
    return getRandomIntFromArray(allowedDurations, 5);
}

/*
 Returns a unique name.
 */
char getUniqueName() {
    char uniqueName = currentLetter;
    ++currentLetter;
    return uniqueName;
}

Process * newProcess() {
    Process * newProcess = (Process *)malloc(sizeof(Process));
    newProcess->size = getRandomSize();
    newProcess->duration = getRandomDuration();
    newProcess->name = getUniqueName();
    return newProcess;
}

void deleteProcess(Process * process) {
    free(process);
}

int getProcessSize(Process * process) {
    return process->size;
}

int getProcessDuration(Process * process) {
    return process->duration;
}

char getProcessName(Process * process) {
    return  process->name;
}
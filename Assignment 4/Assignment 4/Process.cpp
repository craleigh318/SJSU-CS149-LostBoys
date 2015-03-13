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

char Process::currentLetter = 'A';

int Process::getRandomIntFromArray(const int * array, const int arraySize) {
    int randomInt = rand() % arraySize;
    int returnValue = array[randomInt];
    return returnValue;
}

int Process::getRandomSize() {
    return getRandomIntFromArray(allowedSizes, 4);
}

int Process::getRandomDuration() {
    return getRandomIntFromArray(allowedDurations, 5);
}

char Process::getUniqueName() {
    char uniqueName = currentLetter;
    ++currentLetter;
    return uniqueName;
}

Process::Process() :
size(getRandomSize()),
duration(getRandomDuration()),
name(getUniqueName()),
timeAdded(-1)
{
}

int Process::getSize() {
    return size;
}

int Process::getDuration() {
    return duration;
}

char Process::getName() {
    return name;
}

int Process::getTimeAdded() {
	return timeAdded;
}

void Process::setTimeAdded(int time) {
	timeAdded = time;
}

void Process::print() {
    std::cout << "Process: " << name << "\nSize: " << size
    << " MB\nDuration: " << duration << "s\n";
}

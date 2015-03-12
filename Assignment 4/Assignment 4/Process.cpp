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

int Process::getRandomArrivalTime() {
    return (rand() % timeLimit);
}

Process::Process() :
size(getRandomSize()),
duration(getRandomDuration()),
name(getUniqueName()),
arrivalTime(getRandomArrivalTime())
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

void Process::print() {
    std::cout << "Process: " << name << "\nSize: " << size << " MB\nArrival Time: "
    << arrivalTime << " s\nDuration: " << duration << "s\n";
}

bool Process::operator<(Process& other) const
{
    return arrivalTime > other.arrivalTime;
}
//
//  Page.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/14/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Page.h"

Page::Page(int name) :
name(name),
lastTimeUsed(-1),
numTimesUsed(0)
{
}

int Page::getName() {
    return name;
}

int Page::getLastTimeUsed() {
    return lastTimeUsed;
}

void Page::setLastTimeUsed(int time) {
    lastTimeUsed = time;
}

int Page::getNumTimesUsed() {
    return numTimesUsed;
}

int Page::increaseNumTimesUsed() {
    ++numTimesUsed;
    return getNumTimesUsed();
}

void Page::resetNumTimesUsed() {
    numTimesUsed = 0;
}
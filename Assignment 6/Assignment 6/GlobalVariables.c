//
//  GlobalVariables.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/19/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "GlobalVariables.h"

time_t getCurrentTime() {
    time_t currentTime;
    time(&currentTime);
    currentTime -= initialTime;
    return currentTime;
}

void randomSleepTime()
{
    int sleepTime = (rand() % 3); // randomly sleep for 0,1,2 seconds
    sleep(sleepTime);
}

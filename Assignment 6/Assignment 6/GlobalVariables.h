//
//  GlobalVariables.h
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/16/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef Assignment_6_GlobalVariables_h
#define Assignment_6_GlobalVariables_h
#include "SystemHeaders.h"
#define terminateProcessTime 30    // terminate process after 30 seconds
#define NUM_CHILDREN 5
#define READ 0
#define WRITE 1

static time_t initialTime;

static bool finished;

static pthread_mutex_t readWriteMutex;

time_t getCurrentTime();

void randomSleepTime(); // return a random sleep time of 0,1,2 seconds

#endif

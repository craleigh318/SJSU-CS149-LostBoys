//
//  Messaging.h
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_6__Messaging__
#define __Assignment_6__Messaging__
#include "Child.h"
#include "GlobalVariables.h"
#include "SystemHeaders.h"

static double startTime;

void writeToFile(char* message);

void initializeStartTime();

double getTimeInMilli();

void createTimestamp(char *buf);

void createMessage(char * passString, Child * child);

void runChild(Child * child);

void runParent(Child *pipes);

#endif /* defined(__Assignment_6__Messaging__) */

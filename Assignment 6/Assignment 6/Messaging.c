//
//  Messaging.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Messaging.h"

double getTimeInMilli() {
    struct timeval  tv;
    double retTimeInMilli;
    gettimeofday(&tv, NULL);
    retTimeInMilli = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return retTimeInMilli;
}

void createTimestamp(char *buf) {
    char retString[10];
    double curTime;
    curTime = getTimeInMilli();
    int difference = curTime - startTime;
    int second = (int) floor((double) (difference / 1000));
    sprintf(retString, "%i:%02i.%03i", second / 60, second % 60, difference);
    strcpy(buf,retString);
}
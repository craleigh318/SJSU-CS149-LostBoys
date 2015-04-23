//
//  Messaging.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Messaging.h"

void initializeStartTime() {
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    double time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
    startTime = time_in_mill;
}

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

void createMessage(char * passString, Child * child) {
    createTimestamp(passString);
    sprintf(passString, "%s: Child %i message %i\n", passString, child->id, ++(child->numMessages));
}

void runChild(Child * child) {
    char passString[100];
    if(close(child->pipe[READ]) == -1) {
        perror("ERROR: Child Closing Read");
        exit(1);
    }
    while(!finished) {
        randomSleepTime();
        createMessage(passString, child);
        write(child->pipe[WRITE], passString, strlen(passString) + 1);
        finished = true;
    }
    
    if(close(child->pipe[WRITE]) == -1) {
        perror("ERROR: Child Closing Write");
        exit(1);
    }
    //Not sure if this exit call is needed
    exit(0);
}
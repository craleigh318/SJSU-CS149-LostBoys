//
//  main.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/05/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "system_headers.h"
#include "simulated_process.h"

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    struct simulated_process randomProcess = new_simulated_process();
    printf("Arrival Time: %f\nExpected Run Time: %f\nPriority: %d\n", randomProcess.arrivalTime, randomProcess.expectedRunTime, randomProcess.priority);
    return 0;
}
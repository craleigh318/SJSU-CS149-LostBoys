//
//  scheduler_statistics.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/11/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_statistics.h"

struct scheduler_statistics new_scheduler_statistics()
{
    struct scheduler_statistics newSchedulerStatistics =
    {
        0.0f,
        0,
        0.0f,
        0
    };
    return newSchedulerStatistics;
}

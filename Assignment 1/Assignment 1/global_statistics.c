//
//  global_statistics.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/16/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "global_statistics.h"

void reset_global_statistics()
{
    globalStatistics = new_scheduler_statistics();
}
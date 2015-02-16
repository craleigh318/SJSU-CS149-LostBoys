//
//  global_statistics.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/16/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "global_statistics.h"

void add_to_global_statistics(struct scheduler_statistics addingStats)
{
    globalStatistics.response_time += addingStats.response_time;
    globalStatistics.throughput += addingStats.throughput;
    globalStatistics.turnaround_time += addingStats.turnaround_time;
    globalStatistics.waiting_time += addingStats.waiting_time;
}

void reset_global_statistics()
{
    globalStatistics = new_scheduler_statistics();
}
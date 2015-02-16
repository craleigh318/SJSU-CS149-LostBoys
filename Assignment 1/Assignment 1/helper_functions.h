//
//  helper_functions.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__helper_functions__
#define __Assignment_1__helper_functions__
#include "system_headers.h"
#include "simulated_process.h"

static const float TIME_LIMIT = 100.0f;

/*
 Returns a random float, ranging from the specified minimum and maximum.
 */
float getRandomFloat(float minimum, float maximum);

/*
 Returns a random integer, ranging from the specified minimum and maximum.
 */
int getRandomInt(int minimum, int maximum);

/*
 Returns the greater of two floats
 */
float get_max_float(float x, float y);

/*
 Returns the lesser of two floats
 */
float get_min_float(float x, float y);

/*
 Run a quick sort by ARRIVAL time on a passed pointer array of simulated process
 Note: r must be length - 1 on first call
 */
void quick_sort_arrival_time(struct simulated_process * a, int l, int r);

/*
 Run a quick sort by REMAINING time on a passed pointer arry of simulated process
 Note: r must be length - 1 on first call
 */
void quick_sort_run_time(struct simulated_process * a, int l, int r);

#endif /* defined(__Assignment_1__helper_functions__) */

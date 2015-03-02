//
//  global_variables.h
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/20/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_3__global_variables__
#define __Assignment_3__global_variables__

#include "system_headers.h"

#define END_TIME 120 // 120 seconds or 2 minutes

static bool programIsEnding; // Notifies when the program is ending

static int threadCount = 0; // How many threads we have created

static int studentsDropped = 0; // How many students were dropped

static int studentsAdded = 0; // How many students were added

/*
 Call this near the beginning of the main function.
 */
void initialize_global_variables();

#endif /* defined(__Assignment_3__global_variables__) */

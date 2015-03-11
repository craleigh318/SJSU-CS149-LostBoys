//
//  Process.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__Process__
#define __Assignment_4__Process__
#include "SystemHeaders.h"

/*
 Represents a process on the PC.
 */
typedef struct _Process Process;

/*
 Constructs and returns a new process.
 */
Process * newProcess();

/*
 Constructs and returns a new process.
 */
void deleteProcess(Process * process);

/*
 The size, in MB.
 */
int getProcessSize(Process * process);

/*
 The duration, in seconds.
 */
int getProcessDuration(Process * process);

/*
 The one-letter name of this process.
 */
char getProcessName(Process * process);

#endif /* defined(__Assignment_4__Process__) */

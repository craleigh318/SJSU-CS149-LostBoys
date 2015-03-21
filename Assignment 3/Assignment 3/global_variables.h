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

#define END_TIME 120

static bool programIsEnding;
static int threadCount = 0;
static int studentsDropped = 0;
static int studentsAdded = 0;
static int totalTurnAroundTime = 0;
static int totalGS = 0;
static int totalRS = 0;
static int totalEE = 0;
static pthread_t studentsThread[75];
static int currTime = 0;

/*
 Call this near the beginning of the main function.
 */
void initialize_global_variables();

void addStudent();

void dropStudent();

int getStudentAdded();

int getStudentDropped();

void addTotalGS(int time);

void addTotalRS(int time);

void addTotalEE(int time);

void addTotal(int time);

int getTotal();

int getTotalGS();

int getTotalRS();

int getTotalEE();

#endif /* defined(__Assignment_3__global_variables__) */

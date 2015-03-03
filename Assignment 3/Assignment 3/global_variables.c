//
//  global_variables.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/20/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "global_variables.h"

void initialize_global_variables() {
    programIsEnding = false;
}

void addStudent()
{
    ++studentsAdded;
}

void dropStudent()
{
    ++studentsDropped;
}

int getStudentAdded()
{
    return studentsAdded;
}

int getStudentDropped()
{
    return studentsDropped;
}

void addTotal(int time)
{
    totalTurnAroundTime += time;
}

int getTotal()
{
    return totalTurnAroundTime;
}
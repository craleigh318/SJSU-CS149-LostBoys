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
    pthread_mutex_lock(&results);
    ++studentsAdded;
    pthread_mutex_unlock(&results);
}

void dropStudent()
{
    pthread_mutex_lock(&results);
    ++studentsDropped;
    pthread_mutex_unlock(&results);
}

int getStudentAdded()
{
    return studentsAdded;
}

int getStudentDropped()
{
    return studentsDropped;
}
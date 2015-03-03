//
//  student.h
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/18/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_3__student__
#define __Assignment_3__student__
#include "system_headers.h"
#include "student_type.h"
//#include "student_queue.h"
#include "global_variables.h"

typedef struct {
    
    int idNumber;

    StudentType type;

    int sectionNum;

    int arrivalTime;

    pthread_t thread;
    
    bool result;
    
    int turnAroundTime;
    
} Student;

/*
 Returns a new student with the specified ID.
 */
Student new_student(int idNumber);

/*
 Writes the specified student as a string to the specified char array.
 Have at least 7 chars in the array before calling.
 */
void student_to_string(Student student, char * destination);

/*
 Process a student by attempting to add them into the
 */
void* process_student(void* threadId);

void print_student(Student student);

#endif /* defined(__Assignment_3__student__) */

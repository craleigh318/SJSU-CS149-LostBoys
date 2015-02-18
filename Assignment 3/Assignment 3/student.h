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

typedef struct {
    int idNumber;
    StudentType type;
} Student;

/*
 Returns a new student with the specified ID.
 */
Student new_student(int idNumber);

/*char * student_to_string(Student student);*/

#endif /* defined(__Assignment_3__student__) */

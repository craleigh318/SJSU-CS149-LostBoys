//
//  student.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/18/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "student.h"

Student new_student(int idNumber) {
    Student newStudent = {
        idNumber,
        get_random_student_type()
    };
    return newStudent;
}

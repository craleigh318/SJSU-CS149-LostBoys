//
//  student_type.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/18/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "student_type.h"

StudentType get_random_student_type() {
    return (rand() % 3);
}
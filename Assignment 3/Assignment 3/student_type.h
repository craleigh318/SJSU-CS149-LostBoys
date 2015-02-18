//
//  student_type.h
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/18/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef Assignment_3_student_type_h
#define Assignment_3_student_type_h
#include "system_headers.h"

/*
 Three student types.
 GS: graduating senior
 RS: regular senior
 EE: everyone else
 */
enum student_type {
    gs,
    rs,
    ee
};

/*
 Returns GS, RS, or EE randomly.
 */
enum student_type get_random_student_type();

#endif

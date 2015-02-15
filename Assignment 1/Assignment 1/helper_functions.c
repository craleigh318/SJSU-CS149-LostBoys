//
//  helper_functions.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "helper_functions.h"

const float TIME_LIMIT = 100.0f;

float getRandomFloat(float minimum, float maximum)
{
    float floatWithinOne = ((float)rand()) / ((float)RAND_MAX);
    return (maximum * floatWithinOne) - (minimum * floatWithinOne) + minimum;
}

int getRandomInt(int minimum, int maximum)
{
    return (rand() % (maximum - minimum + 1)) + minimum;
}

float get_max_float(float x, float y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

float get_min_float(float x, float y)
{
    if (x <= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
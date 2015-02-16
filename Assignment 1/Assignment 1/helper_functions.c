//
//  helper_functions.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "helper_functions.h"

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

int partition_run_time(struct simulated_process * a, int l, int r) {
    float pivot;
    struct simulated_process t;
    int i, j;
    pivot = a[l].expectedRunTime;
    i = l;
    j = r + 1;
    
    while (1) {
        do
            ++i;
        while (a[i].expectedRunTime <= pivot && i <= r);
        do
            --j;
        while (a[j].expectedRunTime > pivot);
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quick_sort_run_time(struct simulated_process * a, int l, int r) {
    int j;
    
    if (l < r) {
        j = partition_run_time(a, l, r);
        quick_sort_run_time(a, l, j - 1);
        quick_sort_run_time(a, j + 1, r);
    }
}

int partition_arrival_time(struct simulated_process * a, int l, int r) {
    float pivot;
    struct simulated_process t;
    int i, j;
    pivot = a[l].arrivalTime;
    i = l;
    j = r + 1;
    
    while (1) {
        do
            ++i;
        while (a[i].arrivalTime <= pivot && i <= r);
        do
            --j;
        while (a[j].arrivalTime > pivot);
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quick_sort_arrival_time(struct simulated_process * a, int l, int r) {
    int j;
    
    if (l < r) {
        j = partition_arrival_time(a, l, r);
        quick_sort_arrival_time(a, l, j - 1);
        quick_sort_arrival_time(a, j + 1, r);
    }
}

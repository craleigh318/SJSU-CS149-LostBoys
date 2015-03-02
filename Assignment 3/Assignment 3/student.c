//
//  student.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/18/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "student.h"
#include "student_queue.h"
#include "print_queue.h"

int get_arrival_time() {
    return rand() % END_TIME; // Gets a number from 0 to 120 seconds
}

Student new_student(int idNumber) {
    Student newStudent = {
        idNumber,
        get_random_student_type(), // returns a number 0 - 2 of student type
        get_random_section(), // section.c class returns 0 - 4 of sections
        get_arrival_time() // 0 to 120 seconds
    };
    return newStudent;
}

void student_to_string(Student student, char * destination) {
    StudentType type = student.type;
    char * strType;
    switch (type) {
        case gs:
            strType = "GS";
            break;
        case rs:
            strType = "RS";
            break;
        default:
            strType = "EE";
            break;
    }
    sprintf(destination, "#%d.%s", student.idNumber, strType);
}

void* process_student(void* threadId)
{
    ThreadParams* params = threadId;
    Student student = params->student;
    print_student(student);
    
    Sections* addingSection = NULL;
    if(student.sectionNum == 1)
        addingSection = params->s1;
    else if(student.sectionNum == 2)
        addingSection = params->s2;
    else if(student.sectionNum == 3)
        addingSection = params->s3;
    else if(student.sectionNum == 4) {
        addingSection = params->s1;
        // Steve said change alogrithm
    }
    else
    {
        addingSection = NULL;
    }
    add_student_to_section(addingSection,student); // Sends the student to the section they want to apply to
    pthread_mutex_lock(&addingSection->lock);
    add_student_to_section(addingSection, student);
    sleep(params->processTime);
    //pthread_mutex_unlock(&addingSection->lock);
    free(params);
    pthread_exit(NULL);
}

void print_student(Student student)
{
    char studentString1[65];
    student_to_string(student, studentString1);
    char studentString2[65]; // A string with a length of 65 characters
    sprintf(studentString2, "Student %s (Section: %i   Arrival: %i)",
            studentString1,
            student.sectionNum,
            student.arrivalTime);
    print_pq(studentString2); // sends the studentString to the print queue
}

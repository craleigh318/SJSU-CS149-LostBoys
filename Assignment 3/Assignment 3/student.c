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
    return rand() % END_TIME;
}

Student new_student(int idNumber) {
    Student newStudent;
    newStudent.idNumber = idNumber;
    newStudent.type = get_random_student_type();
    newStudent.sectionNum = get_random_section();
    newStudent.arrivalTime = get_arrival_time();
    newStudent.result = 0;
    newStudent.turnAroundTime = 0;
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
    
    Sections* addingSection = NULL;
    if(student.sectionNum == 1)
        addingSection = params->s1;
    else if(student.sectionNum == 2)
        addingSection = params->s2;
    else if(student.sectionNum == 3)
        addingSection = params->s3;
    else if(student.sectionNum == 4) {
        addingSection = params->s1;
    }
    else
    {
        addingSection = NULL;
    }
    // add_student_to_section(addingSection,student);
    pthread_mutex_lock(&addingSection->lock);
    student.result = add_student_to_section(addingSection, student);
    print_student(student);
    sleep(params->processTime);
    pthread_mutex_unlock(&addingSection->lock);
    free(params);
    pthread_exit(NULL);
}

void setTurnAroundTime(int time)
{
    student->turnAroundTime = time;
}

void print_student(Student student)
{
    char *tf;
    if ( student.result == 0 ) // 0 meaning they are enrolled
        tf = "true";
    else
        tf = "false";
    char studentString1[100];
    student_to_string(student, studentString1);
    char studentString2[100]; // A string with a length of 65 characters
    sprintf(studentString2, "Student %s (Section: %i, Arrival: %i secs, Enrolled in section:%s, Turnaround:%i)",
            studentString1,
            student.sectionNum,
            student.arrivalTime,
            tf, student.turnAroundTime);
    print_pq(studentString2); // sends the studentString to the print queue
}

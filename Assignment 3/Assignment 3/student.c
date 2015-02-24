//
//  student.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/18/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "student.h"
#include "student_queue.h"

int get_arrival_time() {
	return rand() % END_TIME;
}

Student new_student(int idNumber) {
    Student newStudent = {
        idNumber,
        get_random_student_type(),
        get_random_section(),
        get_arrival_time()
    };
    return newStudent;
}

void student_to_string(Student student, char ** destination) {
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
    sprintf(*destination, "#%d.%s", student.idNumber, strType);
}

void* process_student(void* threadId) {
	ThreadParams* params = threadId;
	Student student = params->student;
	print_student(student);

	Sections* addingSection;
	if(student.sectionNum == 1)
		addingSection = params->s1;
	else if(student.sectionNum == 2)
		addingSection = params->s2;
	else if(student.sectionNum == 3)
		addingSection = params->s3;
	else if(student.sectionNum == 4) {
		//change this algorithm
		addingSection = params->s1;
	}

	pthread_mutex_lock(&addingSection->lock);
	add_student_to_section(addingSection, student);
	sleep(params->processTime);
	//pthread_mutex_unlock(&addingSection->lock);
	free(params);
	pthread_exit(NULL);
}

void print_student(Student student) {
	printf("Student %2i   Type: %i   Section: %i   Arrival: %i \n",
			student.idNumber,
			student.type,
			student.sectionNum,
			student.arrivalTime);
}

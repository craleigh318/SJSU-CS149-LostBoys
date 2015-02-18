/*
 * student_queue.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Steve
 */

#ifndef STUDENT_QUEUE_H_
#define STUDENT_QUEUE_H_

#include "system_headers.h"
#include "student.h"
#define MAX_STUDENTS 75

typedef struct {
	/*
	 Length of the queue
	 */
	int length;

	/*
	 Array of students in currently in the queue
	 */
	Student students[MAX_STUDENTS];
} StudentQueue;

StudentQueue new_student_queue();

void push_student_queue(StudentQueue* queue, Student student);

Student pop_student_queue(StudentQueue* queue);

void print_student_queue(StudentQueue queue);

#endif /* STUDENT_QUEUE_H_ */

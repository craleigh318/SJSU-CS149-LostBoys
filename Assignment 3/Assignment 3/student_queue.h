/*
 * student_queue.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Steve
 */

#ifndef STUDENT_QUEUE_H_
#define STUDENT_QUEUE_H_

#include "system_headers.h"
#include "sections.h"
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

/*
 Returns a StudentQueue
 */
StudentQueue new_student_queue();

/*
 Pushes a student to the passed StudentQueue
 */
void push_student_queue(StudentQueue* queue, Student student);

/*
 Peeks at the first student from the front of the queue
 */
Student peek_student_queue(StudentQueue queue);
/*
 Get the first student from the front of the queue
 */
Student pop_student_queue(StudentQueue* queue);

/*
 Prints the passed queue
 */
void print_student_queue(StudentQueue queue);

/*
 Sort the StudentQueue by arrival time of students
 */
void sort_students_arrival(StudentQueue* queue);

void quick_sort_arrival_time(Student * a, int l, int r);

void process_student_queue(StudentQueue* a);

#endif /* STUDENT_QUEUE_H_ */

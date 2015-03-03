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
#include "threaded_queue.h"
#define MAX_STUDENTS 75

typedef struct {
	/*
	 Length of the queue
	 */
	int length;
    
    /*
	 ThreadedQueue of students in currently in the queue
	 */
    ThreadedQueue tq;
} StudentQueue;

static StudentQueue gsQueue;

static StudentQueue rsQueue;

static StudentQueue eeQueue;

typedef struct ThreadParams{
	Student student;

	Sections* s1;

	Sections* s2;

	Sections* s3;

	int processTime;
} ThreadParams;

/*
 Returns a StudentQueue
 */
StudentQueue new_student_queue();

/*
 Pushes a student to the passed StudentQueue
 
 Returns turnaround time.
 */
void push_student_queue(StudentQueue* queue, Student student, int currentTime);

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
void sort_students_arrival(Student * queue);

void quick_sort_arrival_time(Student * a, int l, int r);

void process_student_queue(StudentQueue* queue, Sections* s1, Sections* s2, Sections* s3, pthread_t* studentThreads);

#endif /* STUDENT_QUEUE_H_ */

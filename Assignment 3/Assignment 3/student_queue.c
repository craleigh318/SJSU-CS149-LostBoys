/*
 * student_queue.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Steve
 */

#include "student_queue.h"

StudentQueue new_student_queue() {
	StudentQueue new_queue = {
			0,
			-1
	};
	return new_queue;
}

int partition_arrival_time(Student * a, int l, int r) {
    float pivot;
    Student t;
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

void quick_sort_arrival_time(Student * a, int l, int r) {
    int j;

    if (l < r) {
        j = partition_arrival_time(a, l, r);
        quick_sort_arrival_time(a, l, j - 1);
        quick_sort_arrival_time(a, j + 1, r);
    }
}

void push_student_queue(StudentQueue* queue, Student student) {
	if (queue->length < MAX_STUDENTS) {
		queue->students[queue->length] = student;
		queue->length++;
	} else
		puts("ERROR: Could not push Student to Queue. Enlarge the queue.");
}

Student peek_student_queue(StudentQueue queue) {
	Student ret_student = new_student(-1);
	if(queue.length > 0) {
		ret_student = queue.students[0];
	}
	else
		puts("ERROR: Could not peek a Student from queue. No more students in queue.");
	return ret_student;
}

Student pop_student_queue(StudentQueue* queue)  {
	Student ret_student = new_student(-1);
	if(queue->length > 0) {
		ret_student = queue->students[0];
		queue->length--;
		memmove(&queue->students[0], &queue->students[1], sizeof(queue->students) - sizeof(*queue->students));
	}
	else
		puts("ERROR: Could not pop a Student from queue. No more students in queue.");
	return ret_student;
}

void print_student_queue(StudentQueue queue) {
	for(int i = 0; i < queue.length; i++) {
		Student curr_student = queue.students[i];
		print_student(curr_student);
	}
}

void sort_students_arrival(StudentQueue* queue) {
	quick_sort_arrival_time(queue->students, 0, queue->length - 1);
}

void process_student_queue(StudentQueue* a){
	int processTime = 0;
	if(a->students[0].sectionNum == gs)
		processTime = (rand() % 2) + 1;
	else if(a->students[0].sectionNum == rs)
		processTime = (rand() % 3) + 2;
	else if(a->students[0].sectionNum == ee)
		processTime = (rand() % 4) + 3;

	pop_student_queue(a);
}

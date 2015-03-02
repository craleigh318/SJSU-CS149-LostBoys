/*
 * student_queue.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Steve
 */

#include "student_queue.h"
#include "print_queue.h"

StudentQueue new_student_queue() {
	StudentQueue new_queue = {
			0,
        new_threaded_queue()
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

int push_student_queue(StudentQueue* queue, Student student, int currentTime) {
	int turnaroundTime = currentTime - student.arrivalTime;
    if (queue->length < MAX_STUDENTS) {
        Student * newStudent = malloc(sizeof(student));
        *newStudent = student;
        add_to_threaded_queue(&queue->tq, newStudent);
		queue->length++;
	} else
        print_pq("ERROR: Could not push Student to Queue. Enlarge the queue.");
    return  turnaroundTime;
}

Student peek_student_queue(StudentQueue queue) {
	Student ret_student = new_student(-1);
	if(queue.length > 0) {
        Student * retStudentPtr = queue.tq.queue.head->datum;
        ret_student = *retStudentPtr;
	}
	else
        print_pq("ERROR: Could not peek a Student from queue. No more students in queue.");
	return ret_student;
}

Student pop_student_queue(StudentQueue* queue)  {
	Student ret_student = new_student(-1);
	if(queue->length > 0) {
        Student * retStudentPtr = remove_from_threaded_queue(&queue->tq);
        ret_student = *retStudentPtr;
		queue->length--;
        free(retStudentPtr);
	}
	else
		print_pq("ERROR: Could not pop a Student from queue. No more students in queue.");
	return ret_student;
}

void print_student_queue(StudentQueue queue) {
	/*for(int i = 0; i < queue.length; i++) {
		Student curr_student = queue.students[i];
		print_student(curr_student);
	}*/
}

void sort_students_arrival(Student * queue) {
	quick_sort_arrival_time(queue, 0, MAX_STUDENTS - 1);
}

void process_student_queue(StudentQueue* queue, Sections* s1, Sections* s2, Sections* s3, pthread_t* studentThreads) {
	print_student_queue(*queue);
	Student currStudent = pop_student_queue(queue);

	//Need to free this in student.c
	ThreadParams* params = malloc(sizeof(Student) + (sizeof(Sections) * 3));
	params->student = currStudent;
	params->s1 = s1;
	params->s2 = s2;
	params->s3 = s3;

	int processTime;
	if(currStudent.type == gs)
		processTime = rand() % 2 + 1;
	else if(currStudent.type == rs)
		processTime = rand() % 3 + 2;
	else if(currStudent.type == ee)
		processTime = rand() % 4 + 3;
	params->processTime = processTime;

	int thread = pthread_create(&studentThreads[threadCount++], NULL, process_student, params);
	if (thread) {
        char strTemp[64];
        sprintf(strTemp, "ERROR: Could not create thread. Error code %i", thread);
        print_pq(strTemp);
		exit(0);
	}

}

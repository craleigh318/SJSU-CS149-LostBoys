/*
 * sections.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Saurav
 */
#include "sections.h"

Sections newSections() {
        Sections new_Sections = {
        SIZE_OF_CLASS
        };
    return new_Sections;
}

bool add_student_to_section(Sections* section, Student student) {
	if(section->seatsLeft > 0)
	{
        addStudent(); // succesfully added student
		pthread_mutex_t *mutex = &section->lock;
        pthread_mutex_lock(mutex);
        int seatsTaken = SIZE_OF_CLASS - section->seatsLeft;
        section->addedStudents[seatsTaken] = student;
        section->seatsLeft--;
        pthread_mutex_unlock(mutex);
		return true;
	}
    else
    {
    dropStudent(); //unsuccessful at adding
    return false;
    }
}

void print_section(Sections section) {
	for(int i = 0; i < SIZE_OF_CLASS - section.seatsLeft;i++)
		print_student(section.addedStudents[i]);
}

int get_random_section() {
	return (rand() % 4) + 1;
}

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
	if(section->seatsLeft > 0) // If the section the student is trying to add into has seats open to be added into 
	{
		pthread_mutex_lock(&mut);
		section->addedStudents[SIZE_OF_CLASS - section->seatsLeft] = student; // Add the student into the section 
		section->seatsLeft--;
		pthread_mutex_unlock(&mut);
		return true;
	}
	else
		++studentsDropped;
		return false; // Student unable to be added into section
	
}

void print_section(Sections section) {
	for(int i = 0; i < SIZE_OF_CLASS - section.seatsLeft; i++) {
		print_student(section.addedStudents[i]);
	}
}


int get_random_section() {
	return (rand() % 4) + 1;
}

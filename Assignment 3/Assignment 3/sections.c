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

/*
THREAD 1                        THREAD 2
pthread_mutex_lock (&mut);      
                                pthread_mutex_lock (&mut); 
a = data;                       blocked
a++;                            blocked
data = a;                       blocked
pthread_mutex_unlock (&mut);    blocked
                                b = data;
                                b--;
                                data = b;
                                pthread_mutex_unlock (&mut);
*/

bool add_student_to_section(Sections* section, Student student) {
	if(section->seatsLeft > 0) {
		section->addedStudents[SIZE_OF_CLASS - section->seatsLeft] = student;
		section->seatsLeft--;
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

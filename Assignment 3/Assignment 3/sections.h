/*
 * sections.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Saurav
 */

#ifndef SECTIONS_H_
#define SECTIONS_H_

#include "system_headers.h"
#include "student.h"

#define SIZE_OF_CLASS 20

typedef struct {
    int seatsLeft; // how many remaining seats for the sections are left

    Student addedStudents[SIZE_OF_CLASS]; // Each section has 20 seats for 20 studnts

    pthread_mutex_t lock; // Set this to either 1 or 0
    
} Sections;

/*
 Returns a new set of sections with the specified ID.
 */
Sections newSections();

/*
 Add students in the section they belong to
 */

bool add_student_to_section(Sections* section, Student student);

/*
 print the section
 */
void print_section(Sections section);

/*
 Returns a random section:  1 = Section 1,  2 = Section 2,  3 = Section 3, 4 = no preference
 */
int get_random_section();


#endif /* SECTIONS_H_ */

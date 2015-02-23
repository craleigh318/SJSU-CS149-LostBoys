/*
 * sections.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Saurav
 */
#include "sections.h"

Sections newSections() {
    Sections new_Sections = {
        20
    };
    return new_Sections;
}

int get_random_section() {
	return (rand() % 4) + 1;
}

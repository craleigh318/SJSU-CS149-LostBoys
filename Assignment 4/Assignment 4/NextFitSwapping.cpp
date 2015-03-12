/*
 * NextFitSwapping.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: jr
 */

#include "NextFitSwapping.h"

static int LASTPOS = 0;

bool startNextFit(MainMemory memory, Process* process) {
	std::vector<Partition *> holes = getHolesInMemory(&memory);
	for(int i = 0; i < (signed) holes.size(); i++) {
		Partition * hole = holes.at(i);
		if(process->getSize() <= getPartitionSize(hole)) {
			addProcessToHole(holes.at(i), process);
			return true;
		}
	}
	return false;
}

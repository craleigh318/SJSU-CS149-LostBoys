/*
 * NextFitSwapping.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: jr
 */

#include "NextFitSwapping.h"

static int LASTPOS = 0;

bool startNextFit(MainMemory memory, Process* process) {
	std::vector<Partition> holes = Partition::getHolesInMemory(&memory);
	for(int i = 0; i < (signed) holes.size(); i++) {
		Partition hole = holes.at(i);
		if(process->getSize() <= hole.getSize()) {
            holes.at(i).addProcess(process);
			return true;
		}
	}
	return false;
}

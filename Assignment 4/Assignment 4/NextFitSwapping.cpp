/*
 * NextFitSwapping.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: jr
 */

#include "NextFitSwapping.h"

static int LASTPOS = 0;

int incrementI(int i, int addition, int numHoles) {
    int newPos = LASTPOS + addition;
    newPos %= numHoles;
    return newPos;
}

bool startNextFit(MainMemory * memory, Process* process) {
	std::vector<Partition> holes = Partition::getHolesInMemory(memory);
    int holesSize = (signed) holes.size();
    if (holesSize <= 0) {
        return false;
    }
    int i = LASTPOS;
    do {
        Partition hole = holes.at(i);
        if(process->getSize() <= hole.getSize()) {
            holes.at(i).addProcess(process);
            return true;
        }
        i = incrementI(i, 1, holesSize);
    } while (i != LASTPOS);
	return false;
}

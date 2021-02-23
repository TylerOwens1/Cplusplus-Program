/*
 * Crocodile.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: 2010139_snhu
 */

#include "Crocodile.h"

Crocodile::Crocodile(int t_trackNum, string t_name, int t_numEggs) {
	this->setCode(t_trackNum);
	this->setName(t_name);
	this->setNumEggs(t_numEggs);
}

string Crocodile::getSubType(){
	return "Crocodile";
}



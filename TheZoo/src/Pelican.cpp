/*
 * Pelican.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#include "Pelican.h"

Pelican::Pelican(int t_trackNum, string t_name, int t_numEggs) {
	this->setCode(t_trackNum);
	this->setName(t_name);
	this->setNumEggs(t_numEggs);
}

string Pelican::getSubType(){
	return "Pelican";
}


/*
 * Goose.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#include "Goose.h"


Goose::Goose(int t_trackNum, string t_name, int t_numEggs) {
	this->setCode(t_trackNum);
	this->setName(t_name);
	this->setNumEggs(t_numEggs);
}

string Goose::getSubType(){
	return "Goose";
}

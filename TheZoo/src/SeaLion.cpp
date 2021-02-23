/*
 * SeaLion.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#include "SeaLion.h"

SeaLion::SeaLion(int t_trackNum, string t_name, int t_nurse) {
	this->setCode(t_trackNum);
	this->setName(t_name);
	this->setNurse(t_nurse);
}

string SeaLion::getSubType(){
	return "SeaLion";
}

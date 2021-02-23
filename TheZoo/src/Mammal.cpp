/*
 * Mammal.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#include "Mammal.h"

string Mammal::getType() {
	return "Mammal";
}

int Mammal::getNurse(){
	return this->m_Nurse;
}

int Mammal::getNumEggs() {
	return 0;
}

void Mammal::setNurse(int t_Nurse){
	this->m_Nurse = t_Nurse;
}


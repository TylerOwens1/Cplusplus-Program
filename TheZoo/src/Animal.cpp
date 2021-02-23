/*
 * Animal.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: 2010139_snhu
 *
 */

#include "Animal.h"

int Animal::getCode(){
	return m_code;
}

void Animal::setCode(int t_code){
	m_code = t_code;
}

string Animal::getName(){
	return m_name;
}

void Animal::setName(string t_name){
	m_name = t_name;
}


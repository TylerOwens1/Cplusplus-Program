/*
 * Whale.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#ifndef WHALE_H_
#define WHALE_H_

#include<string>
#include "Animal.h"
#include "Mammal.h"
using namespace std;

class Whale: public Mammal {
	public:
		Whale(int t_trackNum, string t_name, int t_nurse);
		string getSubType();

};

#endif /* WHALE_H_ */

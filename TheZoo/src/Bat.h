/*
 * Bat.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#ifndef BAT_H_
#define BAT_H_

#include<string>
#include "Animal.h"
#include "Mammal.h"
using namespace std;

class Bat: public Mammal {
	public:
		Bat(int t_trackNum, string t_name, int t_nurse);
		string getSubType();

};

#endif /* BAT_H_ */

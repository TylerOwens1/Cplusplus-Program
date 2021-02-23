/*
 * SeaLion.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#ifndef SEALION_H_
#define SEALION_H_


#include<string>
#include "Animal.h"
#include "Mammal.h"
using namespace std;

class SeaLion: public Mammal {
	public:
		SeaLion(int t_trackNum, string t_name, int t_nurse);
		string getSubType();

};

#endif /* SEALION_H_ */

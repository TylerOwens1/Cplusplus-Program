/*
 * Crocodile.h
 *
 *  Created on: Feb 15, 2021
 *      Author: 2010139_snhu
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include<string>
#include "Animal.h"
#include "Oviparous.h"
using namespace std;

class Crocodile: public Oviparous {
	public:
		Crocodile(int t_trackNum, string t_name, int t_numEggs);
		string getSubType();

};


#endif /* CROCODILE_H_ */

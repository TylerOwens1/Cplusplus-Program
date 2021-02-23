/*
 * Goose.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include<string>
#include "Animal.h"
#include "Oviparous.h"
using namespace std;

class Goose: public Oviparous {
	public:
		Goose(int t_trackNum, string t_name, int t_numEggs);
		string getSubType();

};


#endif /* GOOSE_H_ */

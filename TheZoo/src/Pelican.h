/*
 * Pelican.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include<string>
#include "Animal.h"
#include "Oviparous.h"
using namespace std;

class Pelican: public Oviparous {
	public:
		Pelican(int t_trackNum, string t_name, int t_numEggs);
		string getSubType();

};

#endif /* PELICAN_H_ */

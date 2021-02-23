/*
 * Oviparous.h
 *
 *  Created on: Feb 15, 2021
 *      Author: 2010139_snhu
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include<string>
#include"Animal.h"
using namespace std;

class Oviparous: public Animal {
	public:
		string getType();
		int getNumEggs();
		int getNurse();
	protected:
		void setNumEggs(int t_numEggs);
	private:
		int m_NumberOfEggs;
};


#endif /* OVIPAROUS_H_ */

/*
 * Mammal.h
 *
 *  Created on: Feb 19, 2021
 *      Author: 2010139_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include<string>
#include"Animal.h"
using namespace std;

class Mammal: public Animal {
	public:
		string getType();
		int getNumEggs();
		int getNurse();
	protected:
		void setNurse(int t_Nurse);
	private:
		int m_Nurse;
};

#endif /* MAMMAL_H_ */

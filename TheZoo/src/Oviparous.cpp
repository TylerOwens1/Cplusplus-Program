/*
 * Oviparous.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: 2010139_snhu
 *
 *
 *      public:
		virtual string printAnimal() = 0;
		string getType();
		virtual string getSubType() = 0;
		int getNumEggs() = 0;
		int getNurse();
	protected:
		void setNumEggs(int t_numEggs);
		int m_NumberOfEggs;
	private:
		static string TYPE = "Oviparous";
		static int NURSE = 0;
 */

#include "Oviparous.h"

string Oviparous::getType() {
	return "Oviparous";
}

int Oviparous::getNurse(){
	return 0;
}

int Oviparous::getNumEggs() {
	return this ->m_NumberOfEggs;
}

void Oviparous::setNumEggs(int t_numEggs){
	this->m_NumberOfEggs = t_numEggs;
}

/*
 * Animal.h
 *
 *  Created on: Feb 15, 2021
 *      Author: 2010139_snhu
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include<string>
using namespace std;

class Animal {
	public:
		virtual string getType() = 0;
		virtual string getSubType() = 0;
		virtual int getNumEggs() = 0;
		virtual int getNurse() = 0;
		int getCode();
		string getName();
	protected:
		void setCode(int t_code);
		void setName(string t_name);
	private:
		int m_code;
		string m_name;
};



#endif /* ANIMAL_H_ */

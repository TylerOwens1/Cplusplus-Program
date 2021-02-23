#include <iostream>
#include <ctype.h>
#include <vector>
#include <jni.h>
#include <stdio.h>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Animal.h"
#include "Oviparous.h"
#include "Crocodile.h"
#include "Goose.h"
#include "Pelican.h"
#include "Mammal.h"
#include "Bat.h"
#include "Whale.h"
#include "SeaLion.h"

static vector<string> SUBTYPES = {"Crocodile"};

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void clearInput() // helper method to clear console input
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void AddAnimal(vector<Animal*>& t_Zoo)
{
	int trakingNum; // use getline for some of these with char limit?
	string name;
	string type;
	string subType;
	int eggs;
	int nurse;
	cout << "Enter Tracking #: "; // takes in inputs and validates them forcing
	cin >> trakingNum;            // the user into a correct input in a while loop
	while(cin.fail() || trakingNum < 0 || trakingNum > 999999){
		cout << "Tracking number must be positive and less than 6 digits." << endl;
		cout << "Enter Tracking #: ";
		clearInput();
		cin >> trakingNum;
	}
	clearInput();
	cout << "Enter Animal Name: ";
	getline(cin, name);// get line here
	while(cin.fail() || name.size() > 15){
		cout << "Name must be less than 15 characters including whitespace." << endl;
		cout << "Enter Animal Name: ";
		clearInput();
		getline(cin, name);
	}
	cout << "Enter Animal Type: ";
	cin >> type;
	while(cin.fail() || (type != "Oviparous" && type != "Mammal")){
		cout << "Type must be supported, Supported types:" << endl;
		cout << "Oviparous, Mammal" << endl;
		cout << "Enter Animal Type: ";
		clearInput();
		cin >> type;
	}
	clearInput();
	cout << "Enter Animal Sub-Type: ";
	cin >> subType;
	while(cin.fail() || (subType != "Crocodile" && subType != "Goose" && subType != "Pelican"
			&& subType != "Bat" && subType != "Whale" && subType != "SeaLion")){
		cout << "Case Sensitive, type must be supported, Supported types:" << endl;
		cout << "Crocodile, Goose, Pelican, Bat, Whale, SeaLion" << endl;
		cout << "Enter Animal Type: ";
		clearInput();
		cin >> subType;
	}
	clearInput();
	if(type == "Oviparous"){ // only asks for eggs for egg laying animals
		cout << "Enter number of Eggs: ";
		cin >> eggs;
		while(cin.fail() || eggs < 0){
			cout << "Must be a positive Integer" << endl;
			cout << "Enter number of Eggs: ";
			clearInput();
			cin >> eggs;
		}
	}
	else {// geting nursing info for nursing animals
		cout << "Enter 1 for Nursing 0 for not Nursing: ";
		cin >> nurse;
		while(cin.fail() || nurse < 0 || nurse > 1){
			cout << "Must be 1 or 0" << endl;
			cout << "Enter 1 for Nursing 0 for not Nursing: ";
			clearInput();
			cin >> nurse;
		}
	}
	clearInput();
	Animal* tmp; // stores the animal
	if(subType == "Crocodile"){
		tmp = new Crocodile(trakingNum, name, eggs);

	}
	else if(subType == "Goose"){
		tmp = new Goose(trakingNum, name, eggs);

	}
	else if(subType == "Pelican"){
		tmp = new Pelican(trakingNum, name, eggs);
	}
	else if(subType == "Bat"){
		tmp = new Bat(trakingNum, name, nurse);
	}
	else if(subType == "Whale"){
		tmp = new Whale(trakingNum, name, nurse);
	}
	else if(subType == "SeaLion"){
		tmp = new SeaLion(trakingNum, name, nurse);
	}
	cout << "Would you like to store animal: " << tmp->getCode() << ' ' << tmp->getName() << ' ';
	cout << tmp->getType() << ' ' << tmp->getSubType() << ' ' << tmp->getNumEggs() << ' ';
	cout << tmp->getNurse() << endl;
	cout << "Y for yes" << endl;
	char input; // checks with the user before storing the animal
	if(cin >> input && (input == 'Y' || input == 'y'))	{
		t_Zoo.push_back(tmp);
		cout << "Animal added" << endl;
	}
	else {
		cout << "Animal not added" << endl;
	}
}


void RemoveAnimal(vector<Animal*>& t_Zoo)
{

	int trackingNum;
	cout << "Enter Tracking # of animal to be deleted : ";
	cin >> trackingNum; // delets by tracking number
	for(unsigned int i = 0; i < t_Zoo.size(); i++){
		if(t_Zoo.at(i)->getCode() == trackingNum){
			cout << "Would you like to delete animal: " << t_Zoo.at(i)->getName() << endl;
			cout << "Type Y for yes" << endl; // validates this is the animal the user wants gone
			char input;
			if(cin >> input && (input == 'Y' || input == 'y'))	{
				t_Zoo.erase(t_Zoo.begin() + i);
				cout << "Animal removed" << endl;
			}
			else {
				cout << "Animal not removed" << endl;
			}
			return;

		}
	}
	cout << "Tracking Number " << trackingNum << " not found" << endl;
}

void DisplayAnimals(vector<Animal*>& t_Zoo){ // displays all the animals in the vector
	cout << "Track# Name             Type             Sub-type         Eggs   Nurse" << endl;
	cout << "======================================================================" << endl;
	for(unsigned int i = 0; i < t_Zoo.size(); i++){
		cout << right;
		cout << setw(6) << setfill('0') << t_Zoo.at(i)->getCode() << ' ';
		cout << left;
		cout << setw(16) << setfill(' ') << t_Zoo.at(i)->getName() << ' ';
		cout << setw(16) << t_Zoo.at(i)->getType() << ' ';
		cout << setw(16) << t_Zoo.at(i)->getSubType() << ' ';
		cout << setw(6) << t_Zoo.at(i)->getNumEggs() << ' ';
		cout << setw(6) << t_Zoo.at(i)->getNurse() << endl;
	}
}

void LoadDataFromFile(vector<Animal*>& t_Zoo)
{
	ifstream zooFile;
	int trackingNum;
	char nameCharArray[18];
	string name;
	string type;
	string subType;
	int eggs;
	int nurse;
	zooFile.open("zoodata.txt"); // opens the file and loads the data
	if(zooFile.is_open()){
		while(zooFile >> trackingNum){
			zooFile.get(nameCharArray, 17);// name can be more than one word
			name = nameCharArray;
			name.erase (name.begin());// deleting leading whitespace
			zooFile >> type;
			zooFile >> subType;
			zooFile >> eggs;
			zooFile >> nurse;

			if(subType == "Crocodile"){
				Crocodile* tmp = new Crocodile(trackingNum, name, eggs);
				t_Zoo.push_back(tmp);
			}
			else if(subType == "Goose"){
				Goose* tmp = new Goose(trackingNum, name, eggs);
				t_Zoo.push_back(tmp);
			}
			else if(subType == "Pelican"){
				Pelican* tmp = new Pelican(trackingNum, name, eggs);
				t_Zoo.push_back(tmp);
			}
			else if(subType == "Bat"){
				Bat* tmp = new Bat(trackingNum, name, nurse);
				t_Zoo.push_back(tmp);
			}
			else if(subType == "Whale"){
				Whale* tmp = new Whale(trackingNum, name, nurse);
				t_Zoo.push_back(tmp);
			}
			else if(subType == "SeaLion"){
				SeaLion* tmp = new SeaLion(trackingNum, name, nurse);
				t_Zoo.push_back(tmp);
			}
			else { // error if unkown animal supType in file
				cout << "subType: " << subType << " not recognized" << endl;
				cout << "Record: "<< trackingNum << name << type << " not added." << endl;
			}

		}
		zooFile.close();
	}

	cout << "Read data from zoodata.txt file" << endl;
}

void SaveDataToFile(vector<Animal*>& t_Zoo)
{
	ofstream zooFile;
	zooFile.open("zoodata.txt"); // overwrites file data with vecor data

	for(unsigned int i = 0; i < t_Zoo.size(); i++){
		zooFile << right << setfill('0');
		zooFile << setw(6) << setfill('0') << t_Zoo.at(i)->getCode() << ' ';
		zooFile << left << setfill(' ');
		zooFile << setw(16) << t_Zoo.at(i)->getName() << ' ';
		zooFile << setw(16) << t_Zoo.at(i)->getType() << ' ';
		zooFile << setw(16) << t_Zoo.at(i)->getSubType() << ' ';
		zooFile << t_Zoo.at(i)->getNumEggs() << ' ';
		zooFile << t_Zoo.at(i)->getNurse() << endl;
	}
	zooFile.close();
	cout << "Data saved to zoodate.txt" << endl;

}

void DisplayMenu()
{
    vector<Animal*> zooVector;
	char input; // creats the fresh vector and stars the menu loop
	do{
		cout << "Menu" << endl;
		cout << "L - Load Animal Data" << endl;
		cout << "G - Generate Data" << endl;
		cout << "D - Display Animal Data" << endl;
		cout << "A - Add Record" << endl;
		cout << "R - Remove Animal/Delete Record" << endl;
		cout << "S - Save Animal Data" << endl;
		cout << "Q - quit" << endl;
		cin >> input;
		input = toupper(input);
		switch (input){
			case 'L':
				LoadDataFromFile(zooVector);
				break;
			case 'G':
				GenerateData();
				break;
			case 'D':
				DisplayAnimals(zooVector);
				break;
			case 'A':
				AddAnimal(zooVector);
				break;
			case 'R':
				RemoveAnimal(zooVector);
				break;
			case 'S':
				SaveDataToFile(zooVector);
				break;
			case 'Q':
				break;
			default:
				cout << "Command not recognized" << endl;
		}
	clearInput();
	cout << endl;
	}while(toupper(input) != 'Q');
	cout << "Exiting program" << endl;

}



int main()
{
	DisplayMenu();
	return 0;
}

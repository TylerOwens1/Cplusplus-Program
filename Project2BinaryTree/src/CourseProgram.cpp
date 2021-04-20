/*
 * CourseProgram.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: tylerowens
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// course structure, contains a vector for prereqs
struct Course{
	string num;
	string name;
	vector<string> prereqs;
	Course(){
		num = "";
	}
};

// binary tree node structure
struct Node{
	Course course;
	Node* left;
	Node* right;
	Node() {
		left = nullptr;
		right = nullptr;
		course = Course();
	}
};

/*
 * prints the course's number and name
 */
void print(Course course){
	cout << course.num << ", " << course.name << endl;
}

/*
 * prints the courses number, name and prereqs
 */
void printPre(Course course){
	cout << course.num << ", " << course.name << " Course Prerequisites:";
	for(int i = 0; i < course.prereqs.size(); i++){
		cout << " " << course.prereqs.at(i);
	}
	cout << endl << endl;
}

/*
 * prints all the courses in alphabetical order
 */
void inOrderPrint(Node* node){
	if(node != nullptr){
		inOrderPrint(node->left);
		print(node->course);
		inOrderPrint(node->right);
	}
}

/*
 * finds a course by the Id and then prints it with prereqs
 */
void search(string courseId, Node* node){
	if(node == nullptr){
		cout << "Course: " << courseId << " not found" << endl << endl;
	}
	else if(node->course.num == courseId){
		printPre(node->course);
	}
	else if(courseId < node->course.num){
		search(courseId, node->left);
	}
	else {
		search(courseId, node->right);
	}
}

/*
 *	Adds a new course to the binary tree
 *	takes in and return root node
 */
Node* addNode(Course course, Node* node){
	//base case

	if(node == nullptr){
		Node* tmp = new Node();
		tmp->course = course;
		cout << "course added" << endl;
		return tmp;
	}
	//recursive case
	if(course.num < node->course.num){
		cout << "left" << endl;
		node->left = addNode(course, node->left);
	}
	else{
		cout << "right" << endl;
		node->right = addNode(course, node->right);
	}
	return node;
}

/*
 * loads a file of courses from a file path
 * returns pointer to root node
 */
Node* loadCourseFile(string filename, Node* root){
	ifstream inputFs;

	inputFs.open(filename);

	if(!inputFs.is_open()){
		cout << "Could not open file: " << filename << endl << endl;
		return root;
	}

	vector<string> choppedLine;
	string tmp;
	string line;
	string data;
	Course course;

	while(!inputFs.fail()){
		choppedLine.clear();
		getline(inputFs, line);
		stringstream s(line);
		while(getline(s,data,',')){
			choppedLine.push_back(data);
		}
		//chopping up line by commas
		if(choppedLine.size() < 2){
			cout << "Each line in the file must contain course num and name separated by a comma"
					<< endl << "file: " << filename << " not loaded." << endl << endl;
		}
		//storing input in course variable
		course = Course();
		course.num = choppedLine.at(0);
		course.name = choppedLine.at(1);
		for(int i = 2; i < choppedLine.size(); i++){
			course.prereqs.push_back(choppedLine.at(i));
		}
		// adds course to the data structure
		root = addNode(course, root);

	}
	cout << "Data from: " << filename << "added." << endl << endl;

	// returns the pointer to the data structure
	return root;


}

/*
 * menu to load and print courses
 */
int main(int argc, char* argv[]) {

	Node* root = nullptr;

	cout << "Welcome to the course planner." << endl << endl;

	string filePath = "CourseInput.txt";
	string courseId;

	int menuChoice = 0;
	while(menuChoice != 9){
		cout << "   1. Load Data Structure." << endl;
		cout << "   2. Print Course List." << endl;
		cout << "   3. Print Course." << endl;
		cout << "   9. Exit." << endl << endl;
		cout << "What would you like to do? ";
		cin >> menuChoice;

		switch(menuChoice){
		case 1:
			root = loadCourseFile(filePath, root);
			break;
		case 2:
			inOrderPrint(root);
			break;
		case 3:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << endl << "Enter course Id to print: ";
			cin >> courseId;
			search(courseId, root);
			break;
		case 9:
			cout << "Goodbye!";
			break;
		default:
			cout << menuChoice << " is not a valid option." << endl << endl;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

	}
	return 0;
}


/*********************************************************************
** Program name: inputValidation.cpp
** Author: Jacob Anderson
** Date: 10/17/18
** Description: Implementation file for input validation functions
*********************************************************************/

#include <iostream>
#include <sstream>
#include "inputValidation.hpp"

using std::endl;
using std::cin;
using std::cout;
using std::getline;
using std::stringstream;

/*********************************************************************
** Takes a reference to an int as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid int is entered.
*********************************************************************/
void getValidInt(int &input) {
	//initialize variables
	bool whileBool = false;
	char tempChar;
	string tempString;
	
	//stay in loop until input is validated
	while (whileBool == false) {
		
		//get a valid line
		getline(cin, tempString);
		stringstream cinBuffer(tempString);
		
		//attempt to move to input
		cinBuffer >> input;
		
		//Fail if there is an invalid character in front.
		if (cinBuffer.fail()) {
			cout << "Invalid input - do not spell out the number or verify it is less than overflow.\n";
			cout << "Please re-enter the desired integer:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}
		
		//Fail if there is an invalid character behind
		else if (cinBuffer >> tempChar) {
			cout << "Invalid input - please do not enter any characters (including '.') or spaces after the desired integer.\n";
			cout << "Please re-enter the desired integer:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}
		
		//Continue if everything checks out
		else {
			whileBool = true;
		}
	}
}

/*********************************************************************
** Takes a reference to a double as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid double is entered.
*********************************************************************/
void getValidDouble(double &input) {
	bool whileBool = false;
	char tempChar;
	string tempString;
	
	while (whileBool == false) {
		
		getline(cin, tempString);
		stringstream cinBuffer(tempString);
		
		cinBuffer >> input;
		
		if (cinBuffer.fail()) {
			cout << "Invalid input - please do not spell out the number or verify it less than overflow.\n";
			cout << "Please re-enter the desired double:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}
		
		else if (cinBuffer >> tempChar) {
			cout << "Invalid input - please do not enter any characters or spaces after the desired double.\n";
			cout << "Please re-enter the desired double:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}
		
		else {
			whileBool = true;
		}
	}
}

/*********************************************************************
** Takes a reference to a char as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid char is entered.
*********************************************************************/
void getValidChar(char &input) {
	bool whileBool = false;
	char tempChar;
	string tempString;
	
	while (whileBool == false) {
		
		getline(cin, tempString);
		stringstream cinBuffer(tempString);
		
		cinBuffer >> input;
		if (cin.fail()) {
			cout << "Invalid input - please enter a valid int.";
			cout << "Please re-enter the desired character:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}
		
		else if (cinBuffer >> tempChar) {
			cout << "Invalid input - please do not enter any characters or spaces after the desired character.\n";
			cout << "Please re-enter the desired character:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}
		
		else {
			whileBool = true;
		}
	}
}

/*********************************************************************
** Takes a reference to a string as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid line is entered.
*********************************************************************/
void getValidLine(string &input) {
	bool whileBool = false;
	
	while (whileBool == false) {
		getline(cin, input);
		if (cin.fail()) {
			cout << "Invalid input - please type a valid line followed by enter.\n";
			cout << "Please re-enter the desired string:\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			whileBool = true;
		}
	}
}
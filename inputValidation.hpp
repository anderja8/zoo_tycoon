/*********************************************************************
** Program name: inputValidation.hpp
** Author: Jacob Anderson
** Date: 10/15/18
** Description: Header file for input validation functions
*********************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <string>

using std::string;

/*********************************************************************
** Takes a reference to an int as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid int is entered.
*********************************************************************/
void getValidInt(int &input);

/*********************************************************************
** Takes a reference to a double as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid double is entered.
*********************************************************************/
void getValidDouble(double &input);

/*********************************************************************
** Takes a reference to a char as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid char is entered.
*********************************************************************/
void getValidChar(char &input);

/*********************************************************************
** Takes a reference to a string as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid line is entered.
*********************************************************************/
void getValidLine(string &input);

#endif
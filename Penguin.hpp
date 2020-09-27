/*********************************************************************
** Program name: Penguin.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Header file for the penguin class derived from the base
** animal class.
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal {
public:
	/*********************************************************************
	** Default constructor. Sets the member variables equal to penguin
	** specific values
	*********************************************************************/
	Penguin();

	/*********************************************************************
	** Overridden function that returns base food cost
	*********************************************************************/
	double getBaseFoodCost();

	/*********************************************************************
	** Overridden function that returns cost
	*********************************************************************/
	int getCost();

	/*********************************************************************
	** Overridden function that returns the litter size
	*********************************************************************/
	int getNumBabies();

	/*********************************************************************
	** Overridden function that returns the payoff
	*********************************************************************/
	double getPayoff();
};

#endif
/*********************************************************************
** Program name: Tiger.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Header file for the tiger class derived from the base
** animal class.
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal {
public:
	/*********************************************************************
	** Default constructor. Sets the member variables equal to tiger
	** specific values
	*********************************************************************/
	Tiger();

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
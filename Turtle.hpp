/*********************************************************************
** Program name: Turtle.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Header file for the turtle class derived from the base
** animal class.
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal {
public:
	/*********************************************************************
	** Default constructor. Sets the member variables equal to tiger
	** specific values
	*********************************************************************/
	Turtle();

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
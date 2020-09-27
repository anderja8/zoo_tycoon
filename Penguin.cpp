/*********************************************************************
** Program name: Penguin.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Implementation file for the turtle class derived from
** the base animal class.
*********************************************************************/

#include "Animal.hpp"
#include "Penguin.hpp"

/*********************************************************************
** Default constructor. Sets the member variables equal to penguin
** specific values and the age to -1.
*********************************************************************/
Penguin::Penguin() : Animal() {
	cost = 1000;
	numBabies = 5;
	baseFoodCost = (this->baseFoodCost);
	payoff = (this->cost) * 0.10;
}

/*********************************************************************
** Overridden function that returns cost
*********************************************************************/
int Penguin::getCost() {
	return cost;
}

/*********************************************************************
** Overridden function that returns the litter size
*********************************************************************/
int Penguin::getNumBabies() {
	return numBabies;
}

/*********************************************************************
** Overridden function that returns base food cost
*********************************************************************/
double Penguin::getBaseFoodCost() {
	return baseFoodCost;
}

/*********************************************************************
** Overridden function that returns the payoff
*********************************************************************/
double Penguin::getPayoff() {
	return payoff;
}
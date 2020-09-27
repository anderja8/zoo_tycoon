/*********************************************************************
** Program name: Tiger.cpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Implementation file for the tiger class derived from
** the base animal class.
*********************************************************************/

#include "Animal.hpp"
#include "Tiger.hpp"

/*********************************************************************
** Default constructor. Sets the member variables equal to tiger
** specific values and the age to -1.
*********************************************************************/
Tiger::Tiger() : Animal() {
	cost = 10000;
	numBabies = 1;
	baseFoodCost = (this->baseFoodCost) * 5;
	payoff = (this->cost) * 0.20;
}

/*********************************************************************
** Overridden function that returns cost
*********************************************************************/
int Tiger::getCost() {
	return cost;
}

/*********************************************************************
** Overridden function that returns the litter size
*********************************************************************/
int Tiger::getNumBabies() {
	return numBabies;
}

/*********************************************************************
** Overridden function that returns base food cost
*********************************************************************/
double Tiger::getBaseFoodCost() {
	return baseFoodCost;
}

/*********************************************************************
** Overridden function that returns the payoff
*********************************************************************/
double Tiger::getPayoff() {
	return payoff;
}
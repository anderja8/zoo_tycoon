/*********************************************************************
** Program name: Turtle.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Implementation file for the turtle class derived from
** the base animal class.
*********************************************************************/

#include "Animal.hpp"
#include "Turtle.hpp"

/*********************************************************************
** Default constructor. Sets the member variables equal to tiger
** specific values and the age to -1.
*********************************************************************/
Turtle::Turtle() : Animal() {
	cost = 100;
	numBabies = 10;
	baseFoodCost = (this->baseFoodCost) * 0.50;
	payoff = (this->cost) * 0.05;
}

/*********************************************************************
** Overridden function that returns cost
*********************************************************************/
int Turtle::getCost() {
	return cost;
}

/*********************************************************************
** Overridden function that returns the litter size
*********************************************************************/
int Turtle::getNumBabies() {
	return numBabies;
}

/*********************************************************************
** Overridden function that returns base food cost
*********************************************************************/
double Turtle::getBaseFoodCost() {
	return baseFoodCost;
}

/*********************************************************************
** Overridden function that returns the payoff
*********************************************************************/
double Turtle::getPayoff() {
	return payoff;
}
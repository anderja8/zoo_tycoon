/*********************************************************************
** Program name: Animal.cpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Implementation file for the base animal class.
*********************************************************************/

#include "Animal.hpp"
#include "Zoo.hpp"

const double BASEFOODCOST = 20;

/*********************************************************************
** Default constructor. Sets protected variables to dummy values.
*********************************************************************/
Animal::Animal() {
	age = -1;
	cost = -1;
	numBabies = -1;
	baseFoodCost = BASEFOODCOST;
	payoff = -1;
}

/*********************************************************************
** Returns age.
*********************************************************************/
int Animal::getAge() {
	return age;
}

/*********************************************************************
** Sets age to specified input.
*********************************************************************/
void Animal::setAge(int inputAge) {
	age = inputAge;
}

/*********************************************************************
** Increases age by 1.
*********************************************************************/
void Animal::incrementAge() {
	age += 1;
}

/*********************************************************************
** Sets the animal age to -1, which the zoo reads as a dead or non-
** existent animal
*********************************************************************/
void Animal::killAnimal() {
	age = -1;
}
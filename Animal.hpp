/*********************************************************************
** Program name: Animal.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Header file for the base animal class.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
protected:
	int age;
	int cost;
	int numBabies;
	double baseFoodCost;
	double payoff;

public:

	/*********************************************************************
	** Default constructor. Sets protected variables to dummy values.
	*********************************************************************/
	Animal();

	/*********************************************************************
	** Returns age.
	*********************************************************************/
	int getAge();

	/*********************************************************************
	** Sets age to specified input.
	*********************************************************************/
	void setAge(int inputAge);

	/*********************************************************************
	** Increases age by 1.
	*********************************************************************/
	void incrementAge();

	/*********************************************************************
	** Sets the animal age to -1, which the zoo reads as a dead or non-
	** existent animal
	*********************************************************************/
	void killAnimal();

	/*********************************************************************
	** Purely virtual funtion to get the cost.
	*********************************************************************/
	virtual int getCost() = 0;

	/*********************************************************************
	** Purely virtual funtion to get the litter size.
	*********************************************************************/
	virtual int getNumBabies() = 0;

	/*********************************************************************
	** Purely virtual funtion to get the base food cost
	*********************************************************************/
	virtual double getBaseFoodCost() = 0;

	/*********************************************************************
	** Purely virtual funtion to get the payoff
	*********************************************************************/
	virtual double getPayoff() = 0;

	/*********************************************************************
	** Purely virtual funtion to destroy dynamically allocated derived
	** classes.
	*********************************************************************/
	virtual ~Animal() {};
};

#endif
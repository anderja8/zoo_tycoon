/*********************************************************************
** Program name: Zoo.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Header file for the zoo class
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"

class Zoo {
private:
	int numTurtles;
	int maxTurtles;
	Animal* turtles;
	int numPenguins;
	int maxPenguins;
	Animal* penguins;
	int numTigers;
	int maxTigers;
	Animal* tigers;
	double totalMoney;
	int days;

public:
	/*********************************************************************
	** Default constructor. Creates space for 10 turtles, 10 penguins,
	** and 10 tigers. Sets the total money to the global constant, and
	** runs the startupPurchases member function.
	*********************************************************************/
	Zoo();

	/*********************************************************************
	** Prints information on the animals, and gets valid input to purchase
	** those 1-2 of those animals at 1 day old. Finally, sets the age of
	** however many animals were purchased.
	*********************************************************************/
	void startupPurchases();

	/*********************************************************************
	** Prints the menu to purchase a new animal, calls functions to
	** validate input to the menu and create the animals/space if required.
	*********************************************************************/
	void purchaseDialog();

	/*********************************************************************
	** Sets the age of the first open (age = -1) spot in the array of the
	** input species number (1 for turtle, 2 for penguin, 3 for tiger).
	** Sets age to the input integer.
	*********************************************************************/
	void addAnimal(int species, int age);

	/*********************************************************************
	** Uses rand to determine which of the four events to perform.
	** Prints a message specifying which event was chosen.
	*********************************************************************/
	void performEvent();

	/*********************************************************************
	** Runs the sickness event. The total number of animals is determined,
	** and then rand is used to determine which will randomly die (have
	** age set to -1 via the killAnimal function).
	*********************************************************************/
	void sickness();

	/*********************************************************************
	** Creates a random bonus from 250 - 500 for each tiger in the zoo.
	** Prints a message telling the user how this affects them.
	*********************************************************************/
	void attendanceBoom();

	/*********************************************************************
	** Runs the birth event. The total number of animals old enough to
	** give birth is determined, and then rand is used to determine which
	** will give birth. Function to increase array size is called if
	** necessary. Add animal function is called in a loop determined by
	** the species number of babies.
	*********************************************************************/
	void birth();

	/*********************************************************************
	** Doubles the animal array of the input species (1 for turtle, 2 for
	** penguin, 3 for tiger), cleans up the dynamically allocated memory.
	*********************************************************************/
	void doubleAnimalArray(int species);

	/*********************************************************************
	** Calls the other member functions to simulate a day at the zoo.
	*********************************************************************/
	bool anotherDay();

	/*********************************************************************
	** Deletes dynamically allocated data
	*********************************************************************/
	void cleanUpZoo();
};

#endif
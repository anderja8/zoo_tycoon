/*********************************************************************
** Program name: Zoo.hpp
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Implementation file for the zoo class
*********************************************************************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "inputValidation.hpp"
#include <cstdlib>
#include <iostream>

using std::rand;
using std::cout;
using std::endl;
using std::cin;

const double TOTALMONEY = 50000;

/*********************************************************************
** Default constructor. Creates space for 10 turtles, 10 penguins,
** and 10 tigers. Sets the total money to the global constant, and
** runs the startupPurchases member function.
*********************************************************************/
Zoo::Zoo() {
	//intialize all of the input variables
	numTurtles = 0;
	maxTurtles = 10;
	turtles = new Turtle[10];
	numPenguins = 0;
	maxPenguins = 10;
	penguins = new Penguin[10];
	numTigers = 0;
	maxTigers = 10;
	tigers = new Tiger[10];
	totalMoney = TOTALMONEY;
	days = 1;
	this->startupPurchases();
}

/*********************************************************************
** Prints information on the animals, and gets valid input to purchase
** those 1-2 of those animals at 1 day old. Finally, sets the age of
** however many animals were purchased.
*********************************************************************/
void Zoo::startupPurchases() {
	//print welcome screen, rules
	cout << "Welcome to Zoo Tycoon!\n";
	cout << "You now own a zoo, congratulations!\n";
	cout << "Your zoo starts with $" << TOTALMONEY << endl;
	cout << "Your zoo can house three types of animals: Turtles, Penguins, and Tigers\n";
	cout << "Each species has different purchase and food costs, litter size, and daily \npayoff\n\n";

	cout << "Turtle\n";
	cout << "Purchase Costs:" << turtles[1].getCost() << endl;
	cout << "Food Costs:" << turtles[1].getBaseFoodCost() << endl;
	cout << "Litter Size:" << turtles[1].getNumBabies() << endl;
	cout << "Daily Payoff:" << turtles[1].getPayoff() << endl << endl;

	cout << "Penguin\n";
	cout << "Purchase Costs:" << penguins[1].getCost() << endl;
	cout << "Food Costs:" << penguins[1].getBaseFoodCost() << endl;
	cout << "Litter Size:" << penguins[1].getNumBabies() << endl;
	cout << "Daily Payoff:" << penguins[1].getPayoff() << endl << endl;

	cout << "Tiger\n";
	cout << "Purchase Costs:" << tigers[1].getCost() << endl;
	cout << "Food Costs:" << tigers[1].getBaseFoodCost() << endl;
	cout << "Litter Size:" << tigers[1].getNumBabies() << endl;
	cout << "Daily Payoff:" << tigers[1].getPayoff() << endl << endl;

	cout << "You have the option to purchase either 1 or 2 of each of the three animal types.\n";
	
	//get purchase input
	int buyTurtles;
	int buyPenguins;
	int buyTigers;

	bool whileBool = false;
	cout << "Please enter how many turtles you would like to purchase.\n";
	while (whileBool == false) {
		getValidInt(buyTurtles);

		if (buyTurtles > 0 && buyTurtles < 3) {
			whileBool = true;
		}
		else {
			cout << "Invalid integer - please enter either 1 or 2.\n";
		}
	}

	whileBool = false;
	cout << "Please enter how many penguins you would like to purchase.\n";
	while (whileBool == false) {
		getValidInt(buyPenguins);

		if (buyPenguins > 0 && buyPenguins < 3) {
			whileBool = true;
		}
		else {
			cout << "Invalid integer - please enter either 1 or 2.\n";
		}
	}

	whileBool = false;
	cout << "Please enter how many tigers you would like to purchase.\n";
	while (whileBool == false) {
		getValidInt(buyTigers);

		if (buyTigers > 0 && buyTigers < 3) {
			whileBool = true;
		}
		else {
			cout << "Invalid integer - please enter either 1 or 2.\n";
		}
	}
	
	//print choices and new amount of money
	cout << "You have chosen to purchase " << buyTurtles << " turtle(s), " << buyPenguins << " penguin(s), and " << buyTigers << " tiger(s).\n";

	int purchaseCosts = buyTurtles * turtles[1].getCost() + buyPenguins * penguins[1].getCost() + buyTigers * tigers[1].getCost();
	cout << "These purchases will cost $" << purchaseCosts << endl;

	totalMoney = totalMoney - purchaseCosts;
	cout << "There is now $" << totalMoney << " in the bank.\n\n\n";

	//create the purchased animals
	for (int i = 0; i < buyTurtles; i++) {
		numTurtles += 1;
		this->addAnimal(1, 1);
	}

	for (int i = 0; i < buyPenguins; i++) {
		numPenguins += 1;
		this->addAnimal(2, 1);
	}

	for (int i = 0; i < buyTigers; i++) {
		numTigers += 1;
		this->addAnimal(3, 1);
	}
}

/*********************************************************************
** Prints the menu to purchase a new animal, calls functions to
** validate input to the menu and create the animals/space if required.
*********************************************************************/
void Zoo::purchaseDialog() {
	int whileInt = 0;
	int purchaseChoice;

	while (whileInt != 1) {

		cout << "Would you like to purchase an animal today?\n";
		cout << "1. Adult Turtle - $" << turtles[1].getCost() << endl;
		cout << "2. Adult Penguin - $" << penguins[1].getCost() << endl;
		cout << "3. Adult Tiger - $" << tigers[1].getCost() << endl;
		cout << "4. No purchase" << endl;

		bool whileBool = false;

		//get valid input
		while (whileBool == false) {
			getValidInt(purchaseChoice);

			if (purchaseChoice > 0 && purchaseChoice < 5) {
				whileBool = true;
			}
			else {
				cout << "Invalid integer - please enter an integer between 1 and 4.\n";
			}
		}

		//Validate that the user can afford the choice
		if (purchaseChoice == 1) {
			if (totalMoney > turtles[1].getCost()) {
				whileInt = 1;
			}
			else {
				cout << "Sorry, but you cannot afford to purchase a turtle. Please make a different choice.\n\n";
			}
		}
		else if (purchaseChoice == 2) {
			if (totalMoney > penguins[1].getCost()) {
				whileInt = 1;
			}
			else {
				cout << "Sorry, but you cannot afford to purchase a penguin. Please make a different choice.\n\n";
			}
		}
		else if (purchaseChoice == 3) {
			if (totalMoney > tigers[1].getCost()) {
				whileInt = 1;
			}
			else {
				cout << "Sorry, but you cannot afford to purchase a tiger. Please make a different choice.\n\n";
			}
		}
		else {
			whileInt = 1;
		}
	}

	if (purchaseChoice == 1) {
		//add the number of turtles
		numTurtles = numTurtles + 1;

		//double the size of the turtle array if numturtles > maxturtles
		if (numTurtles > maxTurtles) {
			this->doubleAnimalArray(1);
		}

		//add an adult to the turtle array
		this->addAnimal(1, 3);

		//subtract cost from the bank
		totalMoney = totalMoney - turtles[1].getCost();

		//print confirmation
		cout << "An adult turtle has been purchased.\n";
		cout << "There is now $" << totalMoney << " in the bank.\n\n";
	}

	else if (purchaseChoice == 2) {
		//add the number of penguins
		numPenguins = numPenguins + 1;

		//double the size of the penguin array if numpenguins > maxpenguins
		if (numPenguins > maxPenguins) {
			this->doubleAnimalArray(2);
		}

		//add an adult to the penguin array
		this->addAnimal(2, 3);

		//subtract cost from the bank
		totalMoney = totalMoney - penguins[1].getCost();


		//print confirmation
		cout << "An adult penguin has been purchased.\n";
		cout << "There is now $" << totalMoney << " in the bank.\n\n";
	}

	else if (purchaseChoice == 3) {
		//add the number of tigers
		numTigers = numTigers + 1;

		//double the size of the turtle array if numtigers > maxtigers
		if (numTigers > maxTigers) {
			this->doubleAnimalArray(3);
		}

		//add an adult to the tiger array
		this->addAnimal(3, 3);

		//subtract cost from the bank
		totalMoney = totalMoney - tigers[1].getCost();


		//print confirmation
		cout << "An adult tiger has been purchased.\n";
		cout << "There is now $" << totalMoney << " in the bank.\n\n";
	}
}

/*********************************************************************
** Sets the age of the first open (age = -1) spot in the array of the
** input species number (1 for turtle, 2 for penguin, 3 for tiger).
** Sets age to the input integer.
*********************************************************************/
void Zoo::addAnimal(int species, int age) {
	bool whileBool = false;
	int i = 0;

	//If the input species is 1 (turtle) loop through turtle array until an empty spot is found, and set the age in that spot to 0
	if (species == 1) {
		while (whileBool != true) {
			if (turtles[i].getAge() == -1) {
				turtles[i].setAge(age);
				whileBool = true;
			}
			else {
				i += 1;
			}
		}
	}

	//If the input species is 2 (penguin) loop through turtle array until an empty spot is found, and set the age in that spot to 0
	else if (species == 2) {
		while (whileBool != true) {
			if (penguins[i].getAge() == -1) {
				penguins[i].setAge(age);
				whileBool = true;
			}
			else {
				i += 1;
			}
		}
	}

	//If the input species is 3 (tiger) loop through turtle array until an empty spot is found, and set the age in that spot to 0
	else if (species == 3) {
		while (whileBool != true) {
			if (tigers[i].getAge() == -1) {
				tigers[i].setAge(age);
				whileBool = true;
			}
			else {
				i += 1;
			}
		}
	}

	else {
		cout << "Invalid species input to doubleAnimalArray function. Input was: " << species << endl;
	}
}

/*********************************************************************
** Uses rand to determine which of the four events to perform.
** Prints a message specifying which event was chosen.
*********************************************************************/
void Zoo::performEvent() {
	int eventChosen = rand() % 4 + 1;

	if (eventChosen == 1) {
		cout << "A sickness is spreading through zoos today.\n";
		this->sickness();
	}
	else if (eventChosen == 2) {
		cout << "There was an attendance boom at zoos today.\n";
		this->attendanceBoom();
	}
	else if (eventChosen == 3) {
		cout << "A zoo animal is giving birth today.\n";
		this->birth();
	}
	else { //eventChosen = 4 and nothing happens
		cout << "Nothing out of the ordinary happened at the zoo today.\n";
	}
}

/*********************************************************************
** Runs the sickness event. The total number of animals is determined,
** and then rand is used to determine which will randomly die (have
** age set to -1 via the killAnimal function).
*********************************************************************/
void Zoo::sickness() {
	//get the total number of animals
	int totalAnimals = numTurtles + numPenguins + numTigers;
	int animal;

	//decide which animal will die
	if (totalAnimals > 0) {
		animal = rand() % totalAnimals + 1;
	}
	int eligibleCounter = 0;

	if (totalAnimals > 0) {
		if (animal <= numTurtles) {
			//loop through the array, increment eligibleCounter if the animal is eligible to die (age != -1)
			for (int i = 0; i < maxTurtles; i++) {
				if (turtles[i].getAge() != -1) {
					eligibleCounter += 1;

					//if this occurance of the eligible animal is the occurance specified by rand, print out a confirmation
					if (eligibleCounter == (animal)) { //error is right here
						cout << "The zoo's turtle in exhibit spot " << i << " has died from the sickness.\n";

						turtles[i].killAnimal();

						numTurtles = numTurtles - 1;
					}
				}
			}
		}

		else if (animal > numTurtles + numPenguins) {
			//loop through the array, increment eligibleCounter if the animal is eligible to die (age != -1)
			for (int i = 0; i < maxTigers; i++) {
				if (tigers[i].getAge() != -1) {
					eligibleCounter += 1;

					//if this occurance of the eligible animal is the occurance specified by rand, print out a confirmation
					if (eligibleCounter == (animal - (numTurtles + numPenguins))) {
						cout << "The zoo's tiger in exhibit spot " << i << " has died from the sickness.\n";

						tigers[i].killAnimal();

						numTigers = numTigers - 1;
					}
				}
			}
		}

		else {
			for (int i = 0; i < maxPenguins; i++) {
				if (penguins[i].getAge() != -1) {
					eligibleCounter += 1;

					//if this occurance of the eligible animal is the occurance specified by rand, print out a confirmation
					if (eligibleCounter == (animal - (numTurtles))) {
						cout << "The zoo's penguin in exhibit spot " << i << " has died from the sickness.\n";

						penguins[i].killAnimal();

						numPenguins = numPenguins - 1;
					}
				}
			}
		}
	}

	else {
		cout << "However, your zoo has no animals, so no animals got sick.\n";
	}
}

/*********************************************************************
** Creates a random bonus from 250 - 500 for each tiger in the zoo.
** Prints a message telling the user how this affects them.
*********************************************************************/
void Zoo::attendanceBoom() {
	int randBonus = rand() % 251 + 250;

	//print out bonus amount and how much the player made from it
	cout << "The attendance boom resulted in a bonus of $" << randBonus << " for each tiger in the zoo.\n";

	if (numTigers > 0) {
		cout << "Your zoo has " << numTigers << " tigers, so you made a bonus of $" << (randBonus * numTigers) << ".\n";
		totalMoney = totalMoney + (randBonus * numTigers);
	}
	else {
		cout << "Unfortunately, your zoo does not have any tigers so you made no money.\n";
	}
}

/*********************************************************************
** Runs the birth event. The total number of animals old enough to
** give birth is determined, and then rand is used to determine which
** will give birth. Function to increase array size is called if
** necessary. Add animal function is called in a loop determined by
** the species number of babies.
*********************************************************************/
void Zoo::birth() {
	int eligibleTurtles = 0;
	int eligiblePenguins = 0;
	int eligibleTigers = 0;

	//Determine how many of each type of animal are eligible to give birth
	for (int i = 0; i < maxTurtles; i++) {
		if (this->turtles[i].getAge() >= 3) {
			eligibleTurtles += 1;
		}
	}

	for (int i = 0; i < maxPenguins; i++) {
		if (this->penguins[i].getAge() >= 3) {
			eligiblePenguins += 1;
		}
	}

	for (int i = 0; i < maxTigers; i++) {
		if (this->tigers[i].getAge() >= 3) {
			eligibleTigers += 1;
		}
	}

	int totalEligibleAnimals = eligibleTurtles + eligiblePenguins + eligibleTigers;

	//if applicable, decide which of the eligible animals will give birth
	if (totalEligibleAnimals > 0) {
		int animal = rand() % totalEligibleAnimals + 1;

		int eligibleCounter = 0;

		if (animal <= eligibleTurtles) {
			//loop through the array, increment eligibleCounter if the animal is eligible to give birth
			for (int i = 0; i < maxTurtles; i++) {
				if (turtles[i].getAge() >= 3) {
					eligibleCounter += 1;

					//if this occurance of the eligible animal is the occurance specified by rand, print out a confirmation
					if (eligibleCounter == (animal)) {
						cout << "The zoo's turtle in exhibit spot " << i << " gave birth\n";
						cout << "to " << turtles[i].getNumBabies() << " babies.\n";

						//add the number of turtles
						numTurtles = numTurtles + turtles[i].getNumBabies();

						//double the size of the turtle array if numturtles > maxturtles
						if (numTurtles > maxTurtles) {
							this->doubleAnimalArray(1);
						}

						for (int j = 0; j < turtles[i].getNumBabies(); j++) {
							this->addAnimal(1, 0);
						}
					}
				}
			}
		}

		else if (animal > eligibleTurtles + eligiblePenguins) {
			//loop through the array, increment eligibleCounter if the animal is eligible to give birth
			for (int i = 0; i < maxTurtles; i++) {
				if (tigers[i].getAge() >= 3) {
					eligibleCounter += 1;

					//if this occurance of the eligible animal is the occurance specified by rand, print out a confirmation
					if (eligibleCounter == (animal - (numTurtles + numPenguins))) {
						cout << "The zoo's tiger in exhibit spot " << i << " gave birth\n";
						cout << "to " << tigers[i].getNumBabies() << " babies.\n";

						//add the number of turtles
						numTigers = numTigers + tigers[i].getNumBabies();

						//double the size of the turtle array if numturtles > maxturtles
						if (numTigers > maxTigers) {
							this->doubleAnimalArray(3);
						}

						for (int j = 0; j < tigers[i].getNumBabies(); j++) {
							this->addAnimal(3, 3);
						}
					}
				}
			}
		}

		else {
			//loop through the array, increment eligibleCounter if the animal is eligible to give birth
			for (int i = 0; i < maxPenguins; i++) {
				if (penguins[i].getAge() >= 3) {
					eligibleCounter += 1;

					//if this occurance of the eligible animal is the occurance specified by rand, print out a confirmation
					if (eligibleCounter == (animal - (numTurtles))) {
						cout << "The zoo's penguin in exhibit spot " << i << " gave birth\n";
						cout << "to " << penguins[i].getNumBabies() << " babies.\n";

						//add the number of turtles
						numPenguins = numPenguins + penguins[i].getNumBabies();

						//double the size of the turtle array if numturtles > maxturtles
						if (numPenguins > maxPenguins) {
							this->doubleAnimalArray(2);
						}

						for (int j = 0; j < penguins[i].getNumBabies(); j++) {
							this->addAnimal(2, 3);
						}
					}
				}
			}
		}
	}
	
	else {
		cout << "Unfortunately, your zoo does not have any animals old enough to give bith.\n";
	}
}

/*********************************************************************
** Doubles the animal array of the input species (1 for turtle, 2 for
** penguin, 3 for tiger), cleans up the dynamically allocated memory.
*********************************************************************/
void Zoo::doubleAnimalArray(int species) {
	if (species == 1) {
		Animal* tempTurtles = new Turtle[maxTurtles];
		int oldMax = maxTurtles;

		for (int i = 0; i < maxTurtles; i++) {
			tempTurtles[i] = this->turtles[i];
		}
		
		delete[] turtles;

		maxTurtles = maxTurtles * 2;

		turtles = new Turtle[maxTurtles];
		for (int i = 0; i < oldMax; i++) {
			turtles[i] = tempTurtles[i];
		}

		delete[] tempTurtles;
		tempTurtles = NULL;
	}

	else if (species == 2) {
		Animal* tempPenguins = new Penguin[maxPenguins];
		int oldMax = maxPenguins;

		for (int i = 0; i < maxPenguins; i++) {
			tempPenguins[i] = this->penguins[i];
		}
		
		delete[] penguins;

		maxPenguins = maxPenguins * 2;

		penguins = new Penguin[maxPenguins];
		for (int i = 0; i < oldMax; i++) {
			penguins[i] = tempPenguins[i];
		}

		delete[] tempPenguins;
		tempPenguins = NULL;
	}

	else if (species == 3) {
		Animal* tempTigers = new Tiger[maxTigers];
		int oldMax = maxTigers;

		for (int i = 0; i < maxTigers; i++) {
			tempTigers[i] = this->tigers[i];
		}
		
		delete[] tigers;

		maxTigers = maxTigers * 2;

		tigers = new Tiger[maxTigers];
		for (int i = 0; i < oldMax; i++) {
			tigers[i] = tempTigers[i];
		}

		delete[] tempTigers;
		tempTigers = NULL;
	}
	
	else {
		cout << "Invalid species input to doubleAnimalArray function. Input was: " << species << endl;
	}
}

/*********************************************************************
** Calls the other member functions to simulate a day at the zoo.
*********************************************************************/
bool Zoo::anotherDay() {
	cout << "Beginning day " << days << " at the zoo.\n";
	cout << "The total money in the zoo bank is: $" << totalMoney << endl;

	//increment the age of the animals, and get a count of what is in the zoo
	int babyTurtles = 0;
	int adultTurtles = 0;
	int babyPenguins = 0;
	int adultPenguins = 0;
	int babyTigers = 0;
	int adultTigers = 0;

	for (int i = 0; i < maxTurtles; i++) {
		if (turtles[i].getAge() != -1) {
			turtles[i].incrementAge();
		}

		if (turtles[i].getAge() >= 3) {
			adultTurtles += 1;
		}
		else if (turtles[i].getAge() != -1) {
			babyTurtles += 1;
		}
	}

	for (int i = 0; i < maxPenguins; i++) {
		if (penguins[i].getAge() != -1) {
			penguins[i].incrementAge();
		}

		if (penguins[i].getAge() >= 3) {
			adultPenguins += 1;
		}
		else if (penguins[i].getAge() != -1) {
			babyPenguins += 1;
		}
	}

	for (int i = 0; i < maxTigers; i++) {
		if (tigers[i].getAge() != -1) {
			tigers[i].incrementAge();
		}

		if (tigers[i].getAge() >= 3) {
			adultTigers += 1;
		}
		else if (tigers[i].getAge() != -1) {
			babyTigers += 1;
		}
	}

	//Print the zoo inventory
	cout << "The zoo inventory is:\n";
	cout << "Young Turtles: " << babyTurtles << endl;
	cout << "Adult Turtles: " << adultTurtles << endl;
	cout << "Young Penguins: " << babyPenguins << endl;
	cout << "Adult Penguins: " << adultPenguins << endl;
	cout << "Young Tigers: " << babyTigers << endl;
	cout << "Adult Tigers: " << adultTigers << endl << endl;

	//determine total food cost
	int totalFoodCosts = numTurtles * turtles[0].getBaseFoodCost() + numPenguins * penguins[0].getBaseFoodCost() + numTigers * tigers[0].getBaseFoodCost();

	cout << "The cost to feed the animals is $" << totalFoodCosts << endl;

	totalMoney = totalMoney - totalFoodCosts;

	if (totalMoney <= 0) {
		cout << "Unfortunately, your zoo does not have enough money in the bank to feed your animals and has to close. Game over.\n";
		return false;
	}

	//store the old money total for profit calculation
	double priorMoney = totalMoney;

	//run the random event
	this->performEvent();

	//Determine how much money was made if there was a boom in attendance
	int bonusMoney = 0;
	if (priorMoney != totalMoney) {
		bonusMoney = totalMoney - priorMoney;
	}

	//Calculate the payoff from all of the zoo animals and print
	int zooPayoff = numTurtles * turtles[0].getPayoff() + numPenguins * penguins[0].getPayoff() + numTigers * tigers[0].getPayoff();

	totalMoney = totalMoney + zooPayoff;

	cout << "The net payoff for all of the animals in the zoo is $" << zooPayoff << endl;

	if (bonusMoney != 0) {
		cout << "Combined with the attendance boom, the total payoff for the day is $" << (zooPayoff + bonusMoney) << endl;
	}

	//Print the total amount of money in the bank
	cout << "The total amount of money in the bank now is $" << totalMoney << endl << endl;

	//Ask if the user would like to purchase an animal.
	this->purchaseDialog();

	//increment the days
	days += 1;

	//the day is now over, return true
	return true;
}

/*********************************************************************
** Deletes dynamically allocated data
*********************************************************************/
void Zoo::cleanUpZoo() {
	delete[] turtles;
	turtles = NULL;

	delete[] penguins;
	penguins = NULL;

	delete[] tigers;
	tigers = NULL;
}
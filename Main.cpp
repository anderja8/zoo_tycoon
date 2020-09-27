/*********************************************************************
** Program name: Project2_Anderson_Jacob
** Author: Jacob Anderson
** Date: 10/11/18
** Description: Simulates the video game zoo tycoon where the user
** owns a zoo. The zoo spends money to feed the animals, gets a payoff
** from attendance based on the animals, lets the user buy new animals,
** and deals with random zoo events like sickness, births, and
** attendance booms.
*********************************************************************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
	//initialize variables
	Zoo zoo;
	bool whileBool = true;
	int endChoice;
	int whileInt = 0;
	srand(time(0));

	//loop through days until the user opts to quit
	while (whileBool == true) {
		whileBool = zoo.anotherDay();

		//if required here to not print this menu before quiting should the user run out of money
		if (whileBool == true) {

			//print ending menu
			cout << "The day is now over. Please choose what to do now.\n";
			cout << "1. Start a new day.\n";
			cout << "2. Quit\n";

			//get valid input
			while (whileInt == 0) {
				getValidInt(endChoice);

				if (endChoice > 0 && endChoice < 3) {
					whileInt = 1;
				}
				else {
					cout << "Invalid integer - please enter either 1 or 2.\n";
				}
			}
			whileInt = 0;

			cout << "\n\n";

			//exit loop if user so chooses
			if (endChoice == 2) {
				whileBool = false;
			}
		}
	}

	//delete dynamic memory
	zoo.cleanUpZoo();

	return 0;
}
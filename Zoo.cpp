/************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description:     The source code file for the Zoo class and functions
**					to operate the Zoo Tycoon game.
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Zoo.hpp"

using std::cout;
using std::cin;
using std::endl;

/*Default constructor that sets values of member variables for the start
of a game and dynamically allocates memory for an array of 10 animals for
each of the type of animal. */
Zoo::Zoo()
{
    money = 25000;
    day = 1;
    dailyFoodCost = 0;
    bankrupt = false;

    numTigers = 0;
    numPenguins = 0;
    numTurtles = 0;

	tigerArraySize = 10;
    penguinArraySize = 10;
    turtleArraySize = 10;

	tigers = new Tiger * [10];
	penguins = new Penguin * [10];
	turtles = new Turtle * [10];
}

//Function returns the amount of money the user has
float Zoo::getMoney()
{
	return money;
}

//Function to print the menu for the user to play the game
int Zoo::menu()
{
    //Variable to hold the choice the user selects from the menu
	int choice;

	cout << "Welcome to Zoo Tycoon!" << endl;
	cout << "Ready to get into the animal business?" << endl;
	cout << "1. Play the game" << endl;
	cout << "2. Quit" << endl;
	cout << "Please enter 1 or 2 to make your selection." << endl;
	cin >> std::setw(1) >> choice;
	
	/*Checks that user makes a valid selection from the menu options
	 * and prompts them to input a valid selection of 1 or 2 until they
	 * do. This while loop will check for char values, integers greater
	 * than 2 or less than 1. The setw(1) will ensure only the first
	 * piece of user input is set to choice. */
	while (!cin.good() || cin.get() != '\n' || choice > 2 || choice < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Stop monkeying around!" << endl; 
		cout << "Please enter a valid selection." << endl;
		cout << endl;
		cout << "1. Play the game" << endl;
		cout << "2. Quit" << endl;
		cout << "Enter 1 or 2:" << endl;
		cin >> choice;
	}

	//While loop to check and return the choice of the user
	while (choice == 1)
	{	
		playGame();
		return 1;
	}

	while (choice == 2)
	{
		cout << "Quitting game" << endl;
		return 0;
	}

	return 0;
}

/*Function to start the game by finding out how many of each animal
the user wants to buy (1 or 2) and calling functions to add those 
animals to their zoo. */
void Zoo::playGame()
{
	Zoo zoo;

	cout << "Grrrreat choice." << endl;
	cout << "To begin, you must purchase some animals." << endl;
	cout << "You have $" << money << " to spend and must buy ";
	cout << "1 or 2 of each animal type to start." << endl;
	cout << endl;

	//Prompts user for how many tigers they want to buy
	cout << "Each tiger costs $10,000." << endl;
	cout << "How many tigers do you want to buy?" << endl;
	cin >> std::setw(1) >> startTigers;
	
	//Checks that user input valid selection of 1 or 2
	while (!cin.good() || cin.get() != '\n' || startTigers > 2 || startTigers < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "ERROR! Please enter a valid selection." << endl;
		cout << "Would you like to buy 1 or 2 tigers?" << endl;
		cin >> startTigers;
	}	

	//Prompts user for how many penguins they want to buy
	cout << "Each penguin costs $1,000" << endl;
	cout << "How many penguins do you want to buy?" << endl;
	cin >> std::setw(1) >> startPenguins;

	//Checks that user input valid selection of 1 or 2
	while (!cin.good() || cin.get() != '\n' || startPenguins > 2 || startPenguins < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "ERROR! Please enter a valid selection." << endl;
		cout << "Would you like to buy 1 or 2 penguins?" << endl;
		cin >> startPenguins;
	}	

	//Prompts user for how many turtles they want to buy
	cout << "Each turtle costs $100" << endl;
	cout << "How many turtles do you want to buy?" << endl;
	cin >> std::setw(1) >> startTurtles;

	//Checks that user input valid selection of 1 or 2
	while (!cin.good() || cin.get() != '\n' || startTurtles > 2 || startTurtles < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "ERROR! Please enter a valid selection." << endl;
		cout << "Would you like to buy 1 or 2 turtles?" << endl;
		cin >> startTurtles;
	}

	if (startTigers == 2)
	{
		addTiger();
		addTiger();
	}
	else
	{	
		addTiger();
	}

	if (startPenguins == 2)
	{
		addPenguin();
		addPenguin();
	}
	else
	{
		addPenguin();
	}

	if (startTurtles == 2)
	{
		addTurtle();
		addTurtle();
	}
	else
	{
		addTurtle();
	}
}

//Function adds one tiger to the zoo
void Zoo::addTiger()
{
	//Checks the size of the Tiger array and doubles in size if needed
	if (numTigers == tigerArraySize)
	{
		Tiger ** tempArray;
		tempArray = new Tiger *[2 * tigerArraySize];
		for (int i = 0; i < numTigers; i++)
		{
			tempArray[i] = tigers[i];
		}
		tigerArraySize *= 2;
		delete [] tigers;

		tigers = tempArray;
	}

	tigers[numTigers] = new Tiger();
	numTigers++;

	money = money - (tigers[0]->getCost());

	cout << "You now have " << numTigers << " tigers in your zoo." << endl;
	cout << endl;
}

//Function adds one penguin to the zoo
void Zoo::addPenguin()
{
	//Checks the size of the Penguin array and doubles in size if needed
	if (numPenguins == penguinArraySize)
	{
		Penguin ** tempArray;
		tempArray = new Penguin *[2 * penguinArraySize];
		for (int i = 0; i < numPenguins; i++)
		{
			tempArray[i] = penguins[i];
		}
		penguinArraySize *= 2;
		delete [] penguins;

		penguins = tempArray;
	}

	penguins[numPenguins] = new Penguin();
	numPenguins++;
	money = money - (penguins[0]->getCost());

	cout << "You now have " << numPenguins << " penguins in your zoo." << endl;
	cout << endl;
}

void Zoo::addTurtle()
{
	//Checks the size of the Penguin array and doubles in size if needed
	if (numTurtles == turtleArraySize)
	{
		Turtle ** tempArray;
		tempArray = new Turtle *[2 * turtleArraySize];
		for (int i = 0; i < numTurtles; i++)
		{
			tempArray[i] = turtles[i];
		}
		turtleArraySize *= 2;
		delete [] turtles;
		
		turtles = tempArray;
	}

	turtles[numTurtles] = new Turtle();
	numTurtles++;
	money = money - (turtles[0]->getCost());

	cout << "You now have " << numTurtles << " turtles in your zoo." << endl;
	cout << endl;
}


/*Three functions below delete specific animal using a temporary array to obtain
all of the previously existing animals and creates a new array containing the
surviving animals*/
void Zoo::removeTiger()
{
	cout << "There were " << numTigers << " tigers in your zoo, ";
	cout << "but due to an unfortunate outbreak of tigerpox ";
	cout << "one tiger has gotten sick and died." << endl;

	if (numTigers > 0)
	{
		delete tigers[numTigers -1];

		tigers[numTigers -1] = nullptr;
		numTigers--;
	}
	cout << "You have " << numTigers << " tigers left." << endl;
}

void Zoo::removePenguin()
{
	cout << "There were " << numPenguins << " penguins in your zoo, ";
	cout << "but due to an unfortunate outbreak of lockjaw ";
	cout << "one penguin has gotten sick and died." << endl;

	if (numPenguins > 0)
	{
		delete penguins[numPenguins -1];

		penguins[numPenguins -1] = nullptr;
		numPenguins--;
	}
	cout << "You have " << numPenguins << " penguins left." << endl;
}

void Zoo::removeTurtle()
{
	cout << "There were " << numTurtles << " turtles in your zoo, ";
	cout << "but due to an unfortunate outbreak of exploding shell ";
	cout << "one turtle has gotten sick and died." << endl;

	if (numTurtles > 0)
	{
		delete turtles[numTurtles -1];

		turtles[numTurtles -1] = nullptr;
		numTurtles--;
	}
	cout << "You have " << numTurtles << " turtles left." << endl;
}

/*Function to select a random event to occur and call the function
to carry out the event. */
void Zoo::randomEvent()
{
	int event = (rand() % 3) + 1;

	switch (event)
	{
		case 1:
			sickness();
			break;

		case 2:
			reward();
			break;

		case 3:
			newBaby();
			break;

		case 4:
			break;
	} 
}

/*Function to select a random animal type to die and call the
remove function for that animal type. :(  */
void Zoo::sickness()
{
	int choice = (rand() % 3) + 1;

	switch (choice)
	{
		case 1:
			removeTiger();
			break;

		case 2:
			removePenguin();
			break;

		case 3:
			removeTurtle();
			break;
	}
}

//Function to add a bonus to player's current money value
void Zoo::reward() 
{
	cout << "Zoo attendance is booming and visitors are ";
	cout << "flocking to see the tigers." << endl;
	
	int reward;
	int bonus = (rand() % 3) + 1;

	switch (bonus)
	{
		case 1:
			reward = 250;
			tigerBonus = reward * numTigers;
			break;

		case 2:
			reward = 350;
			tigerBonus = reward * numTigers;
			break;

		case 3:
			reward = 500;
			tigerBonus = reward * numTigers;
			break;
		
	}
	cout << "Your zoo has earned a bonus of $" << reward;
	cout << " per tiger in the zoo, which comes to a total of $";
	cout << tigerBonus << "." << endl;	
}

/*Function to select a new animal type at random to have a baby
and call the appropriate funcion to add the baby/ies to the array
of that animal type. */
void Zoo::newBaby()
{
	int choice = (rand() % 3) + 1;
	bool babyBorn = false;

	switch (choice)
	{
		//New baby tiger to be added
		case 1:
			//Loops through all the tigers to check if there is an adult
			for (int i = 0; i < numTigers; i++)
			{
				//Checks if there are any adult tigers
				if (babyBorn == false && (tigers[i]->getAge()) >= 3)
				{
					addTiger();
					money += 10000;
					babyBorn = true;
					cout << "Congratulations! Your zoo now has a new baby tiger!" << endl;
					cout << "You now have " << numTigers << " tigers in your zoo." << endl;
					tigers[numTigers - 1]->setAge(0); 
					break;
				}
			}
			break;

		//Five new baby penguins to be added
		case 2:
			//Loops through all the tigers to check if there is an adult
			for (int i = 0; i < numPenguins; i++)
			{
				//Checks if there are any adult penguins
				if (babyBorn == false && (penguins[i]->getAge()) >= 3)
				{
					for (int i = 0; i < 5; i ++)
					{
						addPenguin();
						money += 1000;
						penguins[numPenguins - 1]->setAge(0);
					}
					babyBorn = true;
					cout << "Congratulations! Your zoo now has a five new baby penguins!" << endl;
					cout << "You now have " << numPenguins << " penguins in your zoo." << endl; 
					break;
				}
			}
			break;

		//Ten new baby turtles to be added
		case 3:
			//Loops through all the tigers to check if there is an adult
			for (int i = 0; i < numTurtles; i++)
			{
				//Checks if there are any adult turtles
				if (babyBorn == false && (turtles[i]->getAge()) >= 3)
				{
					for (int i = 0; i < 10; i++)
					{
						addTurtle();
						money += 100;
						turtles[numTigers - 1]->setAge(0);
					}
					babyBorn = true;
					cout << "Congratulations! Your zoo now has a ten new baby turtles!" << endl;
					cout << "You now have " << numTurtles << " turtles in your zoo." << endl; 
					break;
				}
				break;
			}
	}
} 

/*Function calculates the day's total profit, by adding up the payoff
amounts for all of the animals in the zoo and any bonuses. Adds the
profit from the day to the total amount of money held in the money
member variable. */
int Zoo::profitToday()
{
	int tigerProfit, penguinProfit, turtleProfit;	
	int profitToday;

	/*Calculate the profit of each animal group by its payoff multiplied
	by the number of that type of animal in the zoo. */
	if (numTigers > 0)
	{
		tigerProfit = ((tigers[0]->getPayoff()) * numTigers) + tigerBonus;
		tigerBonus = 0;
	}
	else
	{
		tigerProfit = 0;
	}
	if (numPenguins > 0)
	{
		penguinProfit = ((penguins[0]->getPayoff()) * numPenguins);
	}
	else
	{
		penguinProfit = 0;
	}
	if (numTurtles > 0)
	{
		turtleProfit = ((turtles[0]->getPayoff()) * numTurtles);
	}
	else
	{
		turtleProfit = 0;
	}
	cout << endl;
	cout << "Tiger profit today: $" << tigerProfit << endl;
	cout << "Penguin profit today: $" << penguinProfit << endl;
	cout << "Turtle profit today: $" << turtleProfit <<endl;
	cout << endl;
	profitToday = tigerProfit + penguinProfit + turtleProfit;

	//Add the day's profit to the bank
	money = money + profitToday;

	cout << "Today's total profit is $" << profitToday << "." << endl; 
	cout << "In the bank, you have $" << money << " remaining." << endl;
	cout << endl;
	return profitToday;
} 

/*Function called at the end of a day to increment the day by one for all animals
and the game play. */
void Zoo::anotherDay()
{
	//Increments the game by one day
	day++;

	//Increments the age of each animal by one day
	for (int i = 0; i < numTigers - 1; i++)
	{
		tigers[i]->setAge(tigers[i]->getAge()+1);
	}

	for (int i = 0; i < numPenguins - 1; i++)
	{
		penguins[i]->setAge(penguins[i]->getAge()+1);
	}

	for (int i = 0; i < numTurtles - 1; i++)
	{
		turtles[i]->setAge(turtles[i]->getAge()+1);
	}

	cout << "_______________________________" << endl;
	cout << "Day: " << day << endl;
	cout << "Your zoo currently has:" << endl;
	cout << "Tigers: " << numTigers << endl;
	cout << "Penguins: " << numPenguins << endl;
	cout << "Turtles: " << numTurtles << endl;
	cout << endl;
	cout << "You have $" << money << " before feeding your animals.";
	cout << endl;
}

/*Function to prompt user with options to continue playing, purchase
another animal, or quit. */
int Zoo::continueGame()
{
	int choice;

	cout << "Life's a zoo when you're a Zoo Tycoon." << endl;
	cout << "Please select from the following menu:" << endl;
	cout << "1. Continue the game" << endl;
	cout << "2. Quit" << endl;
	cout << "Please enter 1 or 2 to make your selection." << endl;
	cin >> std::setw(1) >> choice;
	
	/*Checks that user makes a valid selection from the menu options
	 * and prompts them to input a valid selection of 1 or 2 until they
	 * do. This while loop will check for char values, integers greater
	 * than 2 or less than 1. The setw(1) will ensure only the first
	 * piece of user input is set to choice. */
	while (!cin.good() || cin.get() != '\n' || choice > 2 || choice < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Stop monkeying around!" << endl; 
		cout << "Please enter a valid selection." << endl;
		cout << endl;
		cout << "1. Continue the game" << endl;
		cout << "2. Quit" << endl;
		cout << "Enter 1 or 2:" << endl;
		cin >> choice;
	}

	//Checks if the user is bankrupt and quits the game if they are
	if ((getBankrupt()) == true)
	{
		cout << "Unfortunately you have ran out of money." << endl;
		cout << "Thanks for playing Zoo Tycoon, better luck next time." << endl;
		return 0;
	}

	//While loop to check and return the choice of the user
	if ((getBankrupt()) == false && choice == 1)
	{	
		int buyAnimal;
		cout << "Would you like to buy another animal?" << endl;
		cout << "1. Yes, please." << endl;
		cout << "2. No, thank you. " << endl;
		cout << "Please enter 1 or 2 to make your selection." << endl;
		cin >> std::setw(1) >> buyAnimal;

		while (!cin.good() || cin.get() != '\n' || buyAnimal > 2 || buyAnimal < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Stop monkeying around!" << endl; 
			cout << "Please enter a valid selection." << endl;
			cout << endl;
			cout << "1. Yes, please." << endl;
			cout << "2. No, thank you. " << endl;
			cout << "Enter 1 or 2:" << endl;
			cin >> buyAnimal;
		}

		if (buyAnimal == 1)
		{
			int animaltoBuy;
			cout << "What type of animal do you want to buy?" << endl;
			cout << "1. tiger" << endl;
			cout << "2. penguin" << endl;
			cout << "3. turtle" << endl;
			cin >> std::setw(1) >> animaltoBuy;

			while (!cin.good() || cin.get() != '\n' || animaltoBuy > 3 || animaltoBuy < 1)
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Stop monkeying around!" << endl; 
				cout << "Please enter a valid selection." << endl;
				cout << endl;
				cout << "1. tiger" << endl;
				cout << "2. penguin" << endl;
				cout << "3. turtle" << endl;
				cout << "Enter 1, 2, or 3:" << endl;
				cin >> animaltoBuy;
			}

			if (animaltoBuy == 1) //Tiger
			{
				addTiger();
				tigers[numTigers - 1]->setAge(3);
			}

			else if (animaltoBuy == 2) //Penguin
			{
				addPenguin();
				penguins[numPenguins - 1]->setAge(3);
			}

			else if (animaltoBuy == 3) //Turtle
			{
				addTurtle();
				turtles[numTurtles - 1]->setAge(3);
			}
		}

		if (buyAnimal == 2)
		{
			cout << "Let's move on to another day." << endl;
		}
		return 1;
	}

	if (choice == 2)
	{
		cout << "Quitting game." << endl;
		return 0;
	}

	return 0;
}

//Function to get the daily food cost for all the animals in the zoo
float Zoo::getDailyFoodCost()
{
	int tigerFoodCost = 0;
	int penguinFoodCost = 0;
	int turtleFoodCost = 0;

	if (numTigers > 0)
	{
		tigerFoodCost = ((tigers[0]->getFoodCost()) * numTigers);
	}
	if (numPenguins > 0)
	{
		penguinFoodCost = ((penguins[0]->getFoodCost()) * numPenguins);
	}
	if (numTurtles > 0)
	{
		turtleFoodCost = ((turtles[0]->getFoodCost()) * numTurtles);
	}

	float foodCostToday = tigerFoodCost + penguinFoodCost + turtleFoodCost;

	cout << "The total food cost today for the animals in the zoo is $" << foodCostToday;
	cout << "." << endl;

	deductFoodCost(foodCostToday);

	return foodCostToday;
}

//Function to subtract daily food cost from the amount of money the user has
void Zoo::deductFoodCost(float foodCost)
{
	if (money < foodCost)
	{
		cout << "Oh no, you don't have enough money to feed the animals!" << endl;
		setBankrupt(true);
		money = money - foodCost;
	}

	else if (money > foodCost)
	{
		money = money - foodCost;

		cout << endl;
		cout << "After feeding all of the animals today, you have $" << money;
		cout << " remaining in the bank." << endl;
		cout << endl;
	}
}

void Zoo::setBankrupt(bool bankruptIn)
{
	if (bankruptIn == false)
	{
		bankrupt = false;
	}

	if (bankruptIn == true)
	{
		bankrupt = true;
	}
}

bool Zoo::getBankrupt()
{
	return bankrupt;
}

Zoo::~Zoo()
{
	//Free dynamically allocated memory of each animal type
	for (int i = 0; i < numTigers; i++)
	{
		delete [] tigers[i];
	}
	delete [] tigers;

	for (int i = 0; i < numPenguins; i++)
	{
		delete [] penguins[i];
	}
	delete [] penguins;

	for (int i = 0; i < numTurtles; i++)
	{
		delete [] turtles[i];
	}
	delete [] turtles;
}

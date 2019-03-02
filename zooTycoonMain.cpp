/************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description:     The source code file for the main simulation of 
**                  the Zoo Tycoon game. 
*************************************************************************/

#include <iostream>
#include <iomanip>

#include "Zoo.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    //Creates a Zoo object called game
    Zoo game;

    /*Menu function called to prompt the user to play the game or quit.
    If user elects to play the game, playgame() will be called within
    the menu() member function and ask user to purchase one of each animal
    to begin the game. */

	if (game.menu() != 0)
	{
    	/*While loop to call a random event, ask user if they want to 
    	purchase another animal, increment the day, and deduct feeding
    	costs continuously until the user is either out of money or selects 
    	to quit the game when prompted. */
   		while ((game.getBankrupt()) == false)
    	{
            game.randomEvent();
            game.profitToday();
         
		 	if ((game.getMoney()) < 0)
            {
                game.setBankrupt(true);
            }
            
			if (game.continueGame() == 0)
			{
				return 0;
			}
            game.anotherDay();
            game.getDailyFoodCost();
            
			if ((game.getMoney()) < 0)
            {
                game.setBankrupt(true);
            }
    	}

    	//Checks if the user is bankrupt and quits the game if they are
		if (game.getBankrupt() == true)
		{
			cout << "Unfortunately you have ran out of money." << endl;
			cout << "Thanks for playing Zoo Tycoon, better luck next time.";
			cout << endl;
			return 0;
		}
	}

    return 0;
}

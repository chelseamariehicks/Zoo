/*************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description: 	The header file for the Zoo class, which declares the
**					member variables and functions for the Zoo Tycoon game.
**************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo
{
    private:
        int day; //Variable to keep track of the current day in the game
        float money; //Variable to hold player's money, like a bank
        float dailyFoodCost; //Variable for the total daily food cost
        bool bankrupt; //Variable for whether user is bankrupt or not
        int tigerBonus; /*Variable to hold the tiger bonus, if the random
                        event should occur to deliver a bonus that day. */
        

        /*Pointers to pointers used to dynamically allocate arrays of
        uninitialized animals/null pointers. */
        Tiger ** tigers;   
        Penguin ** penguins; 
        Turtle ** turtles;

        //Variables to keep track of the array size for each animal
        int tigerArraySize;
        int penguinArraySize;
        int turtleArraySize;

        //Variables to keep track of the number of each animal
        int numTigers;
        int numPenguins;
        int numTurtles;

        //Variables to keep track of how many of each animal to start with
        int startTigers;
        int startPenguins;
        int startTurtles;

    public:
        Zoo(); //Default constructor
        int menu(); //Function to display the menu
        void playGame(); //Function to start the game with animal purchases
        void anotherDay(); //Function to increment the days
        float getMoney(); //Function to return the amount of money the user has
        float getDailyFoodCost(); //Function to get the daily food cost
        void deductFoodCost(float); //Function to subtract daily food cost from bank
        void randomEvent(); //Function to select a random event to occur
        void sickness(); //Function to kill an animal :(
        void reward(); //Function to add a bonus to player's current money value
        void newBaby(); //Function to create a new animal at random
        int profitToday(); //Function to return the day's profits, add to money
        void setBankrupt(bool); //Function sets bankrupt variable 
        bool getBankrupt(); //Function returns bankrupt variable
        int continueGame(); /*Function checks if user wants to quit, 
                             is bankrupt, or wants to continue */
        
        //Functions to add or remove a particular type of animal
        void addTiger();
        void addPenguin();
        void addTurtle();
        void removeTiger();
        void removePenguin();
        void removeTurtle();

        ~Zoo(); //Destructor

};

#endif
/*************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description:     The source code file for the Penguin child class, which
**                  defines the constructor using setter functions from
**                  the parent class Animal.
*************************************************************************/

#include <iostream>
#include "Penguin.hpp"

using std::cout;
using std::cin;
using std::endl;

//Default constructor for creating a penguin object
Penguin::Penguin()
{
    setAge(1);
    setCost(1000);
    setBabies(5);
    setFoodCost(1);
    setPayoff(100);
}
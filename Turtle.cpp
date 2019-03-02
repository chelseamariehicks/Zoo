/*************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description:     The source code file for the Turtle child class, which
**                  defines the constructor using setter functions from
**                  the parent class Animal.
*************************************************************************/

#include <iostream>
#include "Turtle.hpp"

using std::cout;
using std::cin;
using std::endl;

//Default constructor for creating a turtle object
Turtle::Turtle()
{
    setAge(1);
    setCost(100);
    setBabies(10);
    setFoodCost(0.5);
    setPayoff(5);
}
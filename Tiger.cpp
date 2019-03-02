/*************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description:     The source code file for the Tiger child class, which
**                  defines the constructor using setter functions from
**                  the parent class Animal.
*************************************************************************/

#include <iostream>
#include "Tiger.hpp"

using std::cout;
using std::cin;
using std::endl;

//Default constructor for creating a tiger object
Tiger::Tiger()
{
    setAge(1);
    setCost(10000);
    setBabies(1);
    setFoodCost(5);
    setPayoff(2000);
}

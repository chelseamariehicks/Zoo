/*************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description:     The source code file for the Animal parent class, which
**                  defines the getter and setter functions to be inherited  
**                  by the child classes Penguin, Tiger, and Turtle.
*************************************************************************/

#include <iostream>
#include "Animal.hpp"

using std::cout;
using std::cin;
using std::endl;


//Default constructor -- declared but never defined
Animal::Animal()
{

}

//Setter and getter functions for the age of an animal
void Animal::setAge(int ageIn)
{
    age = ageIn;
}

int Animal::getAge()
{
    return age;
}

//Setter and getter functions for the cost of an animal
void Animal::setCost(float costIn)
{
    cost = costIn;
}

float Animal::getCost()
{
    return cost;
}

//Setter and getter functions for the number of babies an animal has
void Animal::setBabies(int babiesIn)
{
    babies = babiesIn;
}

int Animal::getBabies()
{
    return babies;
}


//Setter and getter functions for the food cost of an animal
//Base food price is $10
void Animal::setFoodCost(float multiplier)
{
    foodCost = BASE_FOOD_COST * multiplier;
}

float Animal::getFoodCost()
{
    return foodCost;
}

//Setter and getter functions for the payoff per day of an animal
void Animal::setPayoff(float payoffIn)
{
    payoff = payoffIn;
}

float Animal::getPayoff()
{
    return payoff;
}


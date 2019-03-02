/*************************************************************************
** Author:          Chelsea Hicks
** Date:            2/3/19
** Description:     The header file for the Animal parent class, which
**                  declares protected member variables and getter and
**                  setter functions to be inherited by the child classes 
**                  Penguin, Tiger, and Turtle.
*************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    protected:
        int age, babies;
        float cost, foodCost, payoff; 
        const int BASE_FOOD_COST = 20;

    public:
        Animal(); //Default constructor 
        void setAge(int);
        int getAge();
        void setCost(float);
        float getCost();
        void setBabies(int);
        int getBabies();
        void setFoodCost(float);
        float getFoodCost();
        void setPayoff(float);
        float getPayoff();
};

#endif

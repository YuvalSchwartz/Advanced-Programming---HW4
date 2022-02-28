/*
 * Animal.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Animal.h"

Animal::Animal()
{
	this->_age = 0;
}

void Animal::increaseAgeByOne()
{
	this->_age++;
}

bool Animal::isAboutToDie()const
{
	return (this->_age == this->_ageAtDeath);
}

/****************** Getters ****************/

int Animal::getAge()const
{
	return this->_age;
}

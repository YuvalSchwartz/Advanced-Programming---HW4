/*
 * Chicken.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Chicken.h"

Chicken::Chicken()
{
	setPuchasePrice();
	setAgeAtDeath();
}

void Chicken::setPuchasePrice()
{
	this->_puchasePrice = chickenPuchasePrice;
}

void Chicken::setAgeAtDeath()
{
	this->_ageAtDeath = chickenAgeAtDeath;
}

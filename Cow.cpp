/*
 * Cow.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Cow.h"

Cow::Cow()
{
	setPuchasePrice();
	setAgeAtDeath();
}

void Cow::setPuchasePrice()
{
	this->_puchasePrice = cowPuchasePrice;
}

void Cow::setAgeAtDeath()
{
	this->_ageAtDeath = cowAgeAtDeath;
}

/*
 * Sheep.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Sheep.h"

Sheep::Sheep()
{
	setPuchasePrice();
	setAgeAtDeath();
}

void Sheep::setPuchasePrice()
{
	this->_puchasePrice = sheepPuchasePrice;
}

void Sheep::setAgeAtDeath()
{
	this->_ageAtDeath = sheepAgeAtDeath;
}

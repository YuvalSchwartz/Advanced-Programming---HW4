/*
 * Egg.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Egg.h"

Egg::Egg()
{
	setPrice();
}

void Egg::setPrice()
{
	this->_price = eggPrice;
}

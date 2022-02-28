/*
 * Milk.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Milk.h"

Milk::Milk()
{
	setPrice();
}

Milk::~Milk() {}

void Milk::setPrice()
{
	this->_price = milkPrice;
}

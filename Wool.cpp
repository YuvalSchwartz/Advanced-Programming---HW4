/*
 * Wool.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Wool.h"

Wool::Wool()
{
	setPrice();
}

void Wool::setPrice()
{
	this->_price = woolPrice;
}

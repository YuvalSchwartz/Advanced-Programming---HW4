/*
 * Milk.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef MILK_H_
#define MILK_H_

#include "Product.h"

class Milk : public Product
{

public:
	static const int milkPrice = 3;
	Milk();
	virtual ~Milk();
	virtual void setPrice();

};

#endif /* MILK_H_ */

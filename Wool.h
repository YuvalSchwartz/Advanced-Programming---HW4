/*
 * Wool.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef WOOL_H_
#define WOOL_H_

#include "Product.h"

class Wool : public Product
{

public:
	static const int woolPrice = 2;
	Wool();
	virtual ~Wool(){};
	virtual void setPrice();

};

#endif /* WOOL_H_ */

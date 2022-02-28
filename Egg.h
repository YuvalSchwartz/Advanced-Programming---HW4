/*
 * Egg.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef EGG_H_
#define EGG_H_

#include "Product.h"

class Egg : public Product
{

public:
	static const int eggPrice = 1;
	Egg();
	virtual ~Egg(){};
	virtual void setPrice();

};

#endif /* EGG_H_ */

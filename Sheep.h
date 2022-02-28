/*
 * Sheep.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef SHEEP_H_
#define SHEEP_H_

#include "Animal.h"

class Sheep : public Animal
{

public:
	static const int sheepPuchasePrice = 5;
	static const int sheepAgeAtDeath = 5;
	Sheep();
	virtual ~Sheep(){};
    virtual void setPuchasePrice();
    virtual void setAgeAtDeath();

};

#endif /* SHEEP_H_ */

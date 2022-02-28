/*
 * Chicken.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef CHICKEN_H_
#define CHICKEN_H_

#include "Animal.h"

class Chicken : public Animal
{

public:
	static const int chickenPuchasePrice = 3;
	static const int chickenAgeAtDeath = 3;
	Chicken();
	virtual ~Chicken(){};
    virtual void setPuchasePrice();
    virtual void setAgeAtDeath();

};

#endif /* CHICKEN_H_ */

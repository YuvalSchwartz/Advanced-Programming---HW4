/*
 * Cow.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef COW_H_
#define COW_H_

#include "Animal.h"

class Cow : public Animal
{

public:
	static const int cowPuchasePrice = 10;
	static const int cowAgeAtDeath = 10;
	Cow();
	virtual ~Cow(){};
    virtual void setPuchasePrice();
    virtual void setAgeAtDeath();

};

#endif /* COW_H_ */

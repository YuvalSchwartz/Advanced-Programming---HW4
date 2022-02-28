/*
 * ChickenException.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef CHICKENEXCEPTION_H_
#define CHICKENEXCEPTION_H_

#include "NegativeNumberOfFarmsException.h"

class ChickenException : public NegativeNumberOfFarmsException
{

public:
	ChickenException(const string msg): NegativeNumberOfFarmsException(msg) {};
	virtual ~ChickenException() {;}

};

#endif /* CHICKENEXCEPTION_H_ */

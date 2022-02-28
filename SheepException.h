/*
 * SheepException.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef SHEEPEXCEPTION_H_
#define SHEEPEXCEPTION_H_

#include "NegativeNumberOfFarmsException.h"

class SheepException : public NegativeNumberOfFarmsException
{

public:
	SheepException(const string msg): NegativeNumberOfFarmsException(msg) {};
	virtual ~SheepException() {;}

};

#endif /* SHEEPEXCEPTION_H_ */

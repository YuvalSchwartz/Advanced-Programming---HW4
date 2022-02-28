/*
 * CowException.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef COWEXCEPTION_H_
#define COWEXCEPTION_H_

#include "NegativeNumberOfFarmsException.h"

class CowException : public NegativeNumberOfFarmsException
{

public:
	CowException(const string msg): NegativeNumberOfFarmsException(msg) {};
	virtual ~CowException() {;}

};

#endif /* COWEXCEPTION_H_ */

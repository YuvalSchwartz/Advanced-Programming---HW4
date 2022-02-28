/*
 * NegativeNumberOfFarmsException.h
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#ifndef NEGATIVENUMBEROFFARMSEXCEPTION_H_
#define NEGATIVENUMBEROFFARMSEXCEPTION_H_

#include <iostream>
#include <exception>
using namespace std;

class NegativeNumberOfFarmsException : public exception
{

protected:
	const string _errorMessage;

public:
	NegativeNumberOfFarmsException(const string msg): _errorMessage(msg) {};
	virtual ~NegativeNumberOfFarmsException() {;}
	const string getInformation()const {return _errorMessage;}

};

#endif /* NEGATIVENUMBEROFFARMSEXCEPTION_H_ */

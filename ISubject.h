/*
 * ISubject.h
 *
 *  Created on: Dec 28, 2021
 *      Author: ise
 */

#ifndef ISUBJECT_H_
#define ISUBJECT_H_

#include "IObserver.h"
#include <iostream>
#include <vector>
using namespace std;

class ISubject //abstract class
{

protected: //Relevant only in inheritances
	vector<IObserver*> _potentialBuyers;

public:
	virtual ~ISubject(){};
	virtual void addPotentialBuyer(IObserver *potentialBuyer) = 0; //pure virtual

};

#endif /* ISUBJECT_H_ */

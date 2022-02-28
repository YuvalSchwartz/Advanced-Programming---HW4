/*
 * IObserver.h
 *
 *  Created on: Dec 28, 2021
 *      Author: ise
 */

#ifndef IOBSERVER_H_
#define IOBSERVER_H_

class IObserver //abstract class
{

public:
	virtual ~IObserver(){};
	virtual int productsBuying(int amountOfProducts) = 0; //pure virtual

};

#endif /* IOBSERVER_H_ */

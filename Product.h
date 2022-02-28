/*
 * Product.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

class Product //abstract class
{

protected: //Relevant only in inheritances
	int _price;

public:
	Product(){};
	virtual ~Product(){};
    virtual void setPrice() = 0; //pure virtual

};

#endif /* PRODUCT_H_ */

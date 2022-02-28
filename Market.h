/*
 * Market.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef MARKET_H_
#define MARKET_H_

#include "Farm.h"
#include <iostream>
#include <vector>
using namespace std;

class Market
{

private:
	int _years;
	vector<Farm*> _farms;

public:
	Market();
	virtual ~Market();
	void createNewFarms();
	int getYear()const;
	void increaseYearsByOne();
	void tradingDay();
	void nextYear();
	void fastForwardYears();
	void printMarketFarms()const;

};

#endif /* MARKET_H_ */

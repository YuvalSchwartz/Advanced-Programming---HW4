/*
 * Market.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Market.h"
#include "CowFarm.h"
#include "SheepFarm.h"
#include "ChickenFarm.h"
#include "CowException.h"
#include "ChickenException.h"
#include "SheepException.h"
#include "NegativeNumberOfFarmsException.h"

Market::Market() {
	this->_years = 0;
}

Market::~Market() {
	for(int i = 0; i < (int)this->_farms.size(); ++i)
		delete this->_farms[i];
	this->_farms.clear();
}

void Market::createNewFarms()
{
	cout << "----Creating new farms----" << endl;
	bool validInput = false;
	int numberOfCowFarms, numberOfSheepFarms, numberOfChickenFarms;
	while(!validInput)
	{
		try
		{
			cout << "How many new cow farms will be added this year?" << endl;
			cin >> numberOfCowFarms;
			if (numberOfCowFarms < 0)
				throw CowException("Insert valid number of cow farms");
			cout << "How many new sheep farms will be added this year?" << endl;
			cin >> numberOfSheepFarms;
			if (numberOfSheepFarms < 0)
				throw SheepException("Insert valid number of sheep farms");
			cout << "How many new chicken farms will be added this year?" << endl;
			cin >> numberOfChickenFarms;
			if (numberOfChickenFarms < 0)
				throw ChickenException("Insert valid number of chicken farms");
			validInput = true;
		}
		catch (const NegativeNumberOfFarmsException& ne)
		{
			cout << ne.getInformation() << endl;
			continue;
		}
	}

	cout << "----Adding new farms to market----" << endl;
	Farm *temp;
	for (int i = 0; i < (numberOfCowFarms + numberOfSheepFarms + numberOfChickenFarms); i++)
	{
		try
		{
			if (i < numberOfCowFarms)
				temp = new CowFarm();
			else if (i >= numberOfCowFarms && i < (numberOfCowFarms + numberOfSheepFarms))
				temp = new SheepFarm();
			else if (i >= (numberOfCowFarms + numberOfSheepFarms) && i < (numberOfCowFarms + numberOfSheepFarms + numberOfChickenFarms))
				temp = new ChickenFarm();
			for(int j = 0; j < (int)this->_farms.size(); j++)
			{
				temp->handleCowFarm(this->_farms[j]);
				temp->handleChickenFarm(this->_farms[j]);
				temp->handleSheepFarm(this->_farms[j]);
				this->_farms[j]->handleCowFarm(temp);
				this->_farms[j]->handleChickenFarm(temp);
				this->_farms[j]->handleSheepFarm(temp);
			}
			this->_farms.push_back(temp);
		}
		catch (const exception& e)
		{
			for(int i = 0; i < (int)this->_farms.size(); ++i)
				delete this->_farms[i];
			this->_farms.clear();
			exit(1);
		}
	}
}

int Market::getYear()const
{
	return this->_years;
}

void Market::tradingDay()
{
	cout << "----Begin Market----" << endl;
	for(Farm* f : this->_farms)
		f->sellProducts();

	cout << "----Buy Animals----" << endl;
	for(Farm* f : this->_farms)
		f->animalsBuying();
}

void Market::increaseYearsByOne()
{
	this->_years++;
}


void Market::nextYear()
{
	this->createNewFarms();
	for(Farm* f : this->_farms)
		f->farmProduction();
	this->tradingDay();
	this->increaseYearsByOne();
	for(Farm* f : this->_farms)
	{
		f->increaseAnimalsByOneYear();
		f->setMoney(f->getMoney() + 10);
	}
}

void Market::fastForwardYears()
{
	int numberOfYears;
	cout << "How many years to fast forward?" << endl;
	cin >> numberOfYears;
	for(int i = 0; i < numberOfYears; i++)
	{
		for(Farm* f : this->_farms)
			f->farmProduction();
		this->tradingDay();
		this->increaseYearsByOne();
		for(Farm* f : this->_farms)
		{
			f->increaseAnimalsByOneYear();
			f->setMoney(f->getMoney() + 10);
		}
	}
}

void Market::printMarketFarms()const
{
	cout << "----Market Farms----" << endl;
	for(Farm* f : this->_farms)
		f->farmPrint();
}




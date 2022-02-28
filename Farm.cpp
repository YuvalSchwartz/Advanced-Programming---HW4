/*
 * Farm.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "Farm.h"

int Farm::farmsNum = 0;

Farm::Farm() {
	farmsNum++;
	this->_id = farmsNum;
	this->_money = 10;
}

Farm::~Farm() {
	for(int i = 0; i < (int)this->_animals.size(); ++i)
		delete this->_animals[i];
	this->_animals.clear();
	for(int i = 0; i < (int)this->_productsMade.size(); ++i)
		delete this->_productsMade[i];
	this->_productsMade.clear();
	for(int i = 0; i < (int)this->_productsBought.size(); ++i)
		delete this->_productsBought[i];
	this->_productsBought.clear();
}

void Farm::increaseAnimalsByOneYear()
{
	vector<Animal*>::iterator it;
	for(it = this->_animals.begin(); it != this->_animals.end(); ++it)
	{
		(*it)->increaseAgeByOne();
		if ((*it)->isAboutToDie())
		{
			delete (*it);
			this->_animals.erase(it);
			it--;
		}
	}
}

void Farm::addPotentialBuyer(IObserver *potentialBuyer)
{
	this->_potentialBuyers.push_back(potentialBuyer);
}

/****************** Getters ****************/

int Farm::getID()const
{
	return this->_id;
}

int Farm::getMoney()const
{
	return this->_money;
}

/****************** Setters ****************/

void Farm::setMoney(int money)
{
	this->_money = money;
}


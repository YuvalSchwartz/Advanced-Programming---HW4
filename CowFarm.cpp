/*
 * CowFarm.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "CowFarm.h"
#include "Cow.h"
#include "Milk.h"
#include "Egg.h"
#include "SheepFarm.h"

CowFarm::CowFarm()
{
	for (int i = 0; i < 3; i++)
		this->_animals.push_back(new Cow());
}

void CowFarm::cowFarmWantsToHaveMe(Farm* f) {}

void CowFarm::chickenFarmWantsToHaveMe(Farm* f)
{
	f->addPotentialBuyer(this);
	cout << "Chicken farm(" << f->getID() << ") Added Cow farm(" << this->getID() << ") to his client list" << endl;
}

void CowFarm::sheepFarmWantsToHaveMe(Farm* f) {}

void CowFarm::handleCowFarm(Farm * f) {}

void CowFarm::handleChickenFarm(Farm * f) {}

void CowFarm::handleSheepFarm(Farm * f)
{
	f->cowFarmWantsToHaveMe(this);
}

void CowFarm::farmProduction()
{
	for(Animal* a : this->_animals)
	{
		for (int j = 0; j < a->getAge(); j++)
			this->_productsMade.push_back(new Milk());
	}
}

int CowFarm::productsBuying(int amountOfProducts)
{
	int amountPossibleToBuy = this->getMoney() / Egg::eggPrice;
	if (amountPossibleToBuy == 0)
		return amountOfProducts;
	int amountToBuy;
	if (amountOfProducts <= amountPossibleToBuy)
		amountToBuy = amountOfProducts;
	else
		amountToBuy = amountPossibleToBuy;
	for(int i = 0; i < amountToBuy; i++)
	{
		this->_productsBought.push_back(new Egg());
		this->setMoney(this->getMoney() - Egg::eggPrice);
	}
	return amountToBuy;
}

void CowFarm::sellProducts()
{
	int amountOfProductsToSell, amountOfProductsBought;
	for(IObserver* buyer : this->_potentialBuyers)
	{
		amountOfProductsToSell = this->_productsMade.size();
		if(amountOfProductsToSell == 0)
			return;
		amountOfProductsBought = buyer->productsBuying(amountOfProductsToSell);
		if(amountOfProductsBought > 0)
		{
			for(int i = 0; i < amountOfProductsBought; i++)
			{
				delete this->_productsMade[this->_productsMade.size() - 1];
				this->_productsMade.pop_back();
			}
			this->setMoney(this->getMoney() + (amountOfProductsBought * Milk::milkPrice));
			cout << "Sheep farm(" << ((SheepFarm*)buyer)->getID() << ") bought " << amountOfProductsBought << " milk for " << (amountOfProductsBought * Milk::milkPrice) << " dollars from Cow farm(" << this->getID() << ")" << endl;
		}
	}
}

void CowFarm::animalsBuying()
{
	int numberOfAnimalsBought = 0;
	while(this->getMoney() >= Cow::cowPuchasePrice)
	{
		this->_animals.push_back(new Cow());
		this->setMoney(this->getMoney() - Cow::cowPuchasePrice);
		numberOfAnimalsBought++;
	}
	if(numberOfAnimalsBought > 0)
		cout << "Cow farm(" << this->getID() << ") bought " << numberOfAnimalsBought << " cows for " << (numberOfAnimalsBought * Cow::cowPuchasePrice) << " dollars" << endl;
}

void CowFarm::farmPrint()const
{
	cout << "Farm Id: " << this->getID() << ", type: Cow farm, Money: " << this->getMoney() << ", Animals: " << this->_animals.size() << " cows, Products: Milk[" << this->_productsMade.size() << "], Wool[0], Eggs[" << this->_productsBought.size() << "]" << endl;
}

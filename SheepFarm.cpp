/*
 * SheepFarm.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#include "SheepFarm.h"
#include "Sheep.h"
#include "Wool.h"
#include "Milk.h"
#include "ChickenFarm.h"

SheepFarm::SheepFarm()
{
	for (int i = 0; i < 3; i++)
		this->_animals.push_back(new Sheep());
}

void SheepFarm::cowFarmWantsToHaveMe(Farm* f)
{
	f->addPotentialBuyer(this);
	cout << "Cow farm(" << f->getID() << ") Added Sheep farm(" << this->getID() << ") to his client list" << endl;
}

void SheepFarm::chickenFarmWantsToHaveMe(Farm* f) {}

void SheepFarm::sheepFarmWantsToHaveMe(Farm* f) {}

void SheepFarm::handleCowFarm(Farm * f) {}

void SheepFarm::handleChickenFarm(Farm * f)
{
	f->sheepFarmWantsToHaveMe(this);
}

void SheepFarm::handleSheepFarm(Farm * f) {}

void SheepFarm::farmProduction()
{
	for(Animal* a : this->_animals)
	{
		for (int j = 0; j < a->getAge(); j++)
			this->_productsMade.push_back(new Wool());
	}
}

int SheepFarm::productsBuying(int amountOfProducts)
{
	int amountPossibleToBuy = this->getMoney() / Milk::milkPrice;
	if (amountPossibleToBuy == 0)
		return amountOfProducts;
	int amountToBuy;
	if (amountOfProducts <= amountPossibleToBuy)
		amountToBuy = amountOfProducts;
	else
		amountToBuy = amountPossibleToBuy;
	for(int i = 0; i < amountToBuy; i++)
	{
		this->_productsBought.push_back(new Milk());
		this->setMoney(this->getMoney() - Milk::milkPrice);
	}
	return amountToBuy;
}

void SheepFarm::sellProducts()
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
			this->setMoney(this->getMoney() + (amountOfProductsBought * Wool::woolPrice));
			cout << "Chicken farm(" << ((ChickenFarm*)buyer)->getID() << ") bought " << amountOfProductsBought << " wool for " << (amountOfProductsBought * Wool::woolPrice) << " dollars from Sheep farm(" << this->getID() << ")" << endl;
		}
	}
}

void SheepFarm::animalsBuying()
{
	int numberOfAnimalsBought = 0;
	while(this->getMoney() >= Sheep::sheepPuchasePrice)
	{
		this->_animals.push_back(new Sheep());
		this->setMoney(this->getMoney() - Sheep::sheepPuchasePrice);
		numberOfAnimalsBought++;
	}
	if(numberOfAnimalsBought > 0)
		cout << "Sheep farm(" << this->getID() << ") bought " << numberOfAnimalsBought << " sheeps for " << (numberOfAnimalsBought * Sheep::sheepPuchasePrice) << " dollars" << endl;
}

void SheepFarm::farmPrint()const
{
	cout << "Farm Id: " << this->getID() << ", type: Sheep farm, Money: " << this->getMoney() << ", Animals: " << this->_animals.size() << " sheep, Products: Milk[" << this->_productsBought.size() << "], Wool[" << this->_productsMade.size() << "], Eggs[0]" << endl;
}

/*
 * ChickenFarm.cpp
 *
 *  Created on: Dec 26, 2021
 *      Author: iseHandleSheepFarm
 */

#include "ChickenFarm.h"
#include "Chicken.h"
#include "Egg.h"
#include "Wool.h"
#include "CowFarm.h"

ChickenFarm::ChickenFarm()
{
	for (int i = 0; i < 3; i++)
		this->_animals.push_back(new Chicken());
}

void ChickenFarm::cowFarmWantsToHaveMe(Farm* f) {}

void ChickenFarm::chickenFarmWantsToHaveMe(Farm* f) {}

void ChickenFarm::sheepFarmWantsToHaveMe(Farm* f)
{
	f->addPotentialBuyer(this);
	cout << "Sheep farm(" << f->getID() << ") Added Chicken farm(" << this->getID() << ") to his client list" << endl;
}

void ChickenFarm::handleCowFarm(Farm * f)
{
	f->chickenFarmWantsToHaveMe(this);
}

void ChickenFarm::handleChickenFarm(Farm * f) {}

void ChickenFarm::handleSheepFarm(Farm * f) {}

void ChickenFarm::farmProduction()
{
	for(Animal* a : this->_animals)
	{
		for (int j = 0; j < a->getAge(); j++)
			this->_productsMade.push_back(new Egg());
	}
}

int ChickenFarm::productsBuying(int amountOfProducts)
{
	int amountPossibleToBuy = this->getMoney() / Wool::woolPrice;
	if (amountPossibleToBuy == 0)
		return amountOfProducts;
	int amountToBuy;
	if (amountOfProducts <= amountPossibleToBuy)
		amountToBuy = amountOfProducts;
	else
		amountToBuy = amountPossibleToBuy;
	for(int i = 0; i < amountToBuy; i++)
	{
		this->_productsBought.push_back(new Wool());
		this->setMoney(this->getMoney() - Wool::woolPrice);
	}
	return amountToBuy;
}

void ChickenFarm::sellProducts()
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
			this->setMoney(this->getMoney() + (amountOfProductsBought * Egg::eggPrice));
			cout << "Cow farm(" << ((CowFarm*)buyer)->getID() << ") bought " << amountOfProductsBought << " eggs for " << (amountOfProductsBought * Egg::eggPrice) << " dollars from Chicken farm(" << this->getID() << ")" << endl;
		}
	}
}

void ChickenFarm::animalsBuying()
{
	int numberOfAnimalsBought = 0;
	while(this->getMoney() >= Chicken::chickenPuchasePrice)
	{
		this->_animals.push_back(new Chicken());
		this->setMoney(this->getMoney() - Chicken::chickenPuchasePrice);
		numberOfAnimalsBought++;
	}
	if(numberOfAnimalsBought > 0)
		cout << "Chicken farm(" << this->getID() << ") bought " << numberOfAnimalsBought << " chickens for " << (numberOfAnimalsBought * Chicken::chickenPuchasePrice) << " dollars" << endl;
}

void ChickenFarm::farmPrint()const
{
	cout << "Farm Id: " << this->getID() << ", type: Chicken Farm, Money: " << this->getMoney() << ", Animals: " << this->_animals.size() << " chickens, Products: Milk[0], Wool[" << this->_productsBought.size() << "], Eggs[" << this->_productsMade.size() << "]" << endl;
}





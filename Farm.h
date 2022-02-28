/*
 * Farm.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef FARM_H_
#define FARM_H_

#include "ISubject.h"
#include "IObserver.h"
#include "Animal.h"
#include "Product.h"

class Farm : public ISubject, public IObserver //abstract class
{

private:
	static int farmsNum;
	int _id;
	int _money;

protected: //Relevant only in inheritances
	vector<Animal*> _animals;
	vector<Product*> _productsMade;
	vector<Product*> _productsBought;

public:
	Farm();
	virtual ~Farm();
	int getID()const;
	int getMoney()const;
	void setMoney(int money);
	void increaseAnimalsByOneYear();
	void addPotentialBuyer(IObserver *potentialBuyer);
	//pure virtuals:
	virtual void cowFarmWantsToHaveMe(Farm* f) = 0;
	virtual void chickenFarmWantsToHaveMe(Farm* f) = 0;
	virtual void sheepFarmWantsToHaveMe(Farm* f) = 0;
	virtual void handleCowFarm(Farm* f) = 0;
	virtual void handleChickenFarm(Farm* f) = 0;
	virtual void handleSheepFarm(Farm* f) = 0;

	virtual void farmProduction() = 0;
	virtual int productsBuying(int amountOfProducts) = 0;
	virtual void sellProducts() = 0;
	virtual void animalsBuying() = 0;
	virtual void farmPrint()const = 0;

};

#endif /* FARM_H_ */

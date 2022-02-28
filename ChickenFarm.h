/*
 * ChickenFarm.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef CHICKENFARM_H_
#define CHICKENFARM_H_

#include "Farm.h"

class ChickenFarm : public Farm
{

public:
	ChickenFarm();
	virtual ~ChickenFarm(){};
	virtual void cowFarmWantsToHaveMe(Farm* f);
	virtual void chickenFarmWantsToHaveMe(Farm* f);
	virtual void sheepFarmWantsToHaveMe(Farm* f);
	virtual void handleCowFarm(Farm * f);
	virtual void handleChickenFarm(Farm * f);
	virtual void handleSheepFarm(Farm * f);

	virtual void farmProduction();
	virtual int productsBuying(int amountOfProducts);
	virtual void sellProducts();
	virtual void animalsBuying();
	virtual void farmPrint()const;

};

#endif /* CHICKENFARM_H_ */

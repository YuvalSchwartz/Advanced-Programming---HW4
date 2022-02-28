/*
 * SheepFarm.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef SHEEPFARM_H_
#define SHEEPFARM_H_

#include "Farm.h"

class SheepFarm : public Farm
{

public:
	SheepFarm();
	virtual ~SheepFarm(){};
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

#endif /* SHEEPFARM_H_ */

/*
 * CowFarm.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef COWFARM_H_
#define COWFARM_H_

#include "Farm.h"

class CowFarm : public Farm
{

public:
	CowFarm();
	virtual ~CowFarm(){};
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

#endif /* COWFARM_H_ */

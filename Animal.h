/*
 * Animal.h
 *
 *  Created on: Dec 26, 2021
 *      Author: ise
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal //abstract class
{

private:
	int _age;

protected: //Relevant only in inheritances
	int _puchasePrice;
	int _ageAtDeath;

public:
	Animal();
	virtual ~Animal(){};
	void increaseAgeByOne();
	bool isAboutToDie()const;
	int getAge()const;
    //pure virtuals:
    virtual void setPuchasePrice() = 0;
    virtual void setAgeAtDeath() = 0;

};

#endif /* ANIMAL_H_ */

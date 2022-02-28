CPP_FARM: Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Egg.o Farm.o farmMarket.o Market.o Milk.o Sheep.o SheepFarm.o Wool.o
	g++ Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Egg.o Farm.o farmMarket.o Market.o Milk.o Sheep.o SheepFarm.o Wool.o -o CPP_FARM

Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp

Chicken.o: Chicken.cpp Chicken.h Animal.h
	g++ -c Chicken.cpp

ChickenFarm.o: ChickenFarm.cpp ChickenFarm.h Farm.h ISubject.h IObserver.h Animal.h Product.h Chicken.h Egg.h Wool.h CowFarm.h
	g++ -c ChickenFarm.cpp

Cow.o: Cow.cpp Cow.h Animal.h
	g++ -c Cow.cpp

CowFarm.o: CowFarm.cpp CowFarm.h Farm.h ISubject.h IObserver.h Animal.h Product.h Cow.h Milk.h Egg.h SheepFarm.h
	g++ -c CowFarm.cpp

Egg.o: Egg.cpp Egg.h Product.h
	g++ -c Egg.cpp

Farm.o: Farm.cpp Farm.h ISubject.h IObserver.h Animal.h Product.h
	g++ -c Farm.cpp

farmMarket.o: farmMarket.cpp Market.h Farm.h ISubject.h IObserver.h Animal.h Product.h
	g++ -c farmMarket.cpp

Market.o: Market.cpp Market.h Farm.h ISubject.h IObserver.h Animal.h Product.h CowFarm.h SheepFarm.h ChickenFarm.h CowException.h NegativeNumberOfFarmsException.h ChickenException.h SheepException.h
	g++ -c Market.cpp

Milk.o: Milk.cpp Milk.h Product.h
	g++ -c Milk.cpp

Sheep.o: Sheep.cpp Sheep.h Animal.h
	g++ -c Sheep.cpp

SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h ISubject.h IObserver.h Animal.h Product.h Sheep.h Wool.h Milk.h ChickenFarm.h
	g++ -c SheepFarm.cpp

Wool.o: Wool.cpp Wool.h Product.h
	g++ -c Wool.cpp
clean:
	rm -f *.o

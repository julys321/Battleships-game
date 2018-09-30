#pragma once
#include "Ocean.h"
#include "Direction.h"
class Player
{
//private:
	
public:
	Ocean ocean;
	//Ocean getOcean();
	bool isThereAShipAtAndAroundCoordinates(int x, int y);
	bool isShipAllowedToDeploy(int lenght, int x, int y, Direction direction);
	void deployShip(int lenght, int x, int y, Direction direction);
	void deployShip(int x, int y);
	Player();
	~Player();
};


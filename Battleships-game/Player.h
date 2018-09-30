#pragma once
#include "Ocean.h"
#include "Direction.h"
class Player
{
private:
	int shipLimits[11]{0,4,3,2,1,0,0,0,0,0};
public:
	Ocean ocean;
	int getShipLimit(int lenght);
	void setShipLimit(int lenght, int limit);
	bool isThereAShipAtAndAroundCoordinates(int x, int y);
	bool isShipAllowedToDeploy(int lenght, int x, int y, Direction direction);
	void deployShip(int lenght, int x, int y, Direction direction);
	void deployShip(int x, int y);
	Player();
	~Player();
};


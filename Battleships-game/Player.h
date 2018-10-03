#pragma once
#include "Ocean.h"
#include "Direction.h"
class Player
{
public:
	int shipLimits[11]{ 0,4,3,2,1,0,0,0,0,0 };
	bool isSkippingATurn=0;
	Ocean ocean;
	int getShipLimit(int lenght);
	void setShipLimit(int lenght, int limit);
	bool isThereAShipAtAndAroundCoordinates(int x, int y);
	bool isShipAllowedToDeploy(int lenght, int x, int y, Direction direction);
	void deployShip(int lenght, int x, int y, Direction direction);
	void deployShip(int x, int y);
	void receiveShot(int x, int y);
	bool areThereRemainingShips();
	bool areAllShipLimitsExceeded();

	Player();
	Player(int shipLimits[]);
	~Player();
};


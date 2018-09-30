#pragma once
#include <vector>
#include "Dependencies.h"
class Ocean
{
private:
	Cell cells[10][10];
public:
	Cell getCellAtCoordinates(int x, int y);
	bool isCellOutOfBounds(int x, int y);
	void setCellAtCoordinates(int x, int y, Cell cell);
	void deployShip(int lenght,int x,int y,Direction direction);
	void deployShip(int x,int y);
	bool equals(Ocean ocean);
	Ocean();
	~Ocean();
};


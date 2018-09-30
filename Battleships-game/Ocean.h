#pragma once
#include <vector>
#include "Cell.h"
class Ocean
{
private:
	Cell cells[10][10];
public:
	Cell getCellAtCoordinates(int x, int y);
	void setCellAtCoordinates(int x, int y, Cell cell);
	bool isCellOutOfBounds(int x, int y);
	bool equals(Ocean ocean);
	Ocean();
	~Ocean();
};


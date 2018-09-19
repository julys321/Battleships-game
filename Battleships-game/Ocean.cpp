#include "Ocean.h"

Cell Ocean::getCellAtCoordinates(int x, int y) {
	return cells[x][y];
}

void Ocean::setCellAtCoordinates(int x, int y, Cell cell) {
	try{
		validateCellCoordinates(x, y);
	}
	catch (std::string exception) {
		throw exception;
	}
	cells[x][y] = cell;
}

void Ocean::deployShip(int lenght, int x, int y, Direction direction) {
	Ocean ocean;
	switch (direction) {
	case Direction::NORTH:
		for (int i = y; i > y - lenght; i--) {
			setCellAtCoordinates(x, i, Cell::INTACT_SHIP);
		}
		return;
	case Direction::EAST:
		for (int j = x; j < lenght; j++) {
			setCellAtCoordinates(j, x, Cell::INTACT_SHIP);
		}
		return;
	case Direction::SOUTH:
		for (int i = y; i < lenght; i++) {
			setCellAtCoordinates(x, i, Cell::INTACT_SHIP);
		}
		return;
	case Direction::WEST:
		for (int j = x; j > x - lenght; j--) {
			setCellAtCoordinates(j, y, Cell::INTACT_SHIP);
		}
		return;
	default:
		return;
	}
}

void Ocean::deployShip(int x, int y) {
	setCellAtCoordinates(x, y, Cell::INTACT_SHIP);
}

bool Ocean::equals(Ocean ocean) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (this->getCellAtCoordinates(i, j) != ocean.getCellAtCoordinates(i, j)) {
				return false;
			}
		}
	}
	return true;
}

void Ocean::validateCellCoordinates(int x, int y) {
	if (
		x > 9
		|| x < 0
		|| y > 9
		|| y < 0
		)
		throw "Cell cannot be placed outside ocean boundaries";
}

Ocean::Ocean() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->cells[i][j] = Cell::WATER;
		}
	}
}


Ocean::~Ocean() {

}

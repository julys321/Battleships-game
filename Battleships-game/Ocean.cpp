#include "Ocean.h"

Cell Ocean::getCellAtCoordinates(int x, int y) {
	if (x > 9 ||
		x < 0 ||
		y > 9 ||
		y < 0)
		return Cell::WATER;
	return cells[x][y];
}

bool Ocean::isCellOutOfBounds(int x, int y) {
	if (x > 9 ||
		x < 0 ||
		y > 9 ||
		y < 0)
		return true;
	return false;
}

void Ocean::setCellAtCoordinates(int x, int y, Cell cell) {
	cells[x][y] = cell;
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

Ocean::Ocean() {
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			this->cells[x][y] = Cell::WATER;
		}
	}
}


Ocean::~Ocean() {

}

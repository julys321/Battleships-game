#include <iostream>
#include "Ocean.h"
int main() {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::EAST);

	Ocean oceanMock;
	oceanMock.setCellAtCoordinates(0, 0, Cell::INTACT_SHIP);
	oceanMock.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	oceanMock.setCellAtCoordinates(2, 0, Cell::INTACT_SHIP);
	bool test = ocean.equals(oceanMock);
	std::cout << "Hello world";
}
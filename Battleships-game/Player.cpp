#include "Player.h"



//Ocean Player::getOcean(){
//	return ocean;
//}


//Ocean getOcean();

bool Player::isThereAShipAtAndAroundCoordinates(int x, int y) {
	if (ocean.getCellAtCoordinates(x - 1, y - 1) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x, y - 1) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x + 1, y - 1) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x - 1, y) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x, y) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x + 1, y) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x - 1, y + 1) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x, y + 1) == Cell::INTACT_SHIP)
		return true;
	if (ocean.getCellAtCoordinates(x + 1, y + 1) == Cell::INTACT_SHIP)
		return true;
	return false;
}

bool Player::isShipAllowedToDeploy(int lenght, int x, int y, Direction direction) {
	switch (direction) {
	case Direction::NORTH:
		for (int i = y; i > y - lenght; i--)
			if (ocean.isCellOutOfBounds(x, i) || isThereAShipAtAndAroundCoordinates(x, i))
				return false;
		return true;
	case Direction::EAST:
		for (int j = x; j < x + lenght; j++)
			if (ocean.isCellOutOfBounds(j, y) || isThereAShipAtAndAroundCoordinates(j, y))
				return false;
		return true;
	case Direction::SOUTH:
		for (int i = y; i < y + lenght; i++)
			if (ocean.isCellOutOfBounds(x, i) || isThereAShipAtAndAroundCoordinates(x, i))
				return false;
		return true;
	case Direction::WEST:
		for (int j = x; j > x - lenght; j--)
			if (ocean.isCellOutOfBounds(j, y) || isThereAShipAtAndAroundCoordinates(j, y))
				return false;
		return true;
	default:
		return false;
	}
}

void Player::deployShip(int lenght, int x, int y, Direction direction) {
	switch (direction) {
	case Direction::NORTH:
		for (int i = y; i > y - lenght; i--) {
			ocean.setCellAtCoordinates(x, i, Cell::INTACT_SHIP);
		}
		return;
	case Direction::EAST:
		for (int j = x; j < x + lenght; j++) {
			ocean.setCellAtCoordinates(j, y, Cell::INTACT_SHIP);
		}
		return;
	case Direction::SOUTH:
		for (int i = y; i < y + lenght; i++) {
			ocean.setCellAtCoordinates(x, i, Cell::INTACT_SHIP);
		}
		return;
	case Direction::WEST:
		for (int j = x; j > x - lenght; j--) {
			ocean.setCellAtCoordinates(j, y, Cell::INTACT_SHIP);
		}
		return;
	}
}

void Player::deployShip(int x, int y) {
	ocean.setCellAtCoordinates(x, y, Cell::INTACT_SHIP);
}

Player::Player()
{
}


Player::~Player()
{
}

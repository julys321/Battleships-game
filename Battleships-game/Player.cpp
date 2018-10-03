#include "Player.h"

int Player::getShipLimit(int lenght) {
	return shipLimits[lenght];
}

void Player::setShipLimit(int lenght, int limit) {
	shipLimits[lenght] = limit;
}

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
	if (getShipLimit(lenght) <= 0)
		return false;
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
	shipLimits[lenght]--;
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
	deployShip(1, x, y, Direction::EAST);
}

void Player::receiveShot(int x, int y) {
	if (ocean.getCellAtCoordinates(x, y) == Cell::INTACT_SHIP)
		ocean.setCellAtCoordinates(x, y, Cell::SUNKEN_SHIP);
	if (ocean.getCellAtCoordinates(x, y) == Cell::WATER)
		ocean.setCellAtCoordinates(x, y, Cell::MISSED_SHOT);
}

bool Player::areThereRemainingShips() {
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			if (ocean.getCellAtCoordinates(x, y) == Cell::INTACT_SHIP)
				return true;
	return false;
}

bool Player::areAllShipLimitsExceeded(){
	for (int i = 0; i < 11; i++)
		if (shipLimits[i] != 0)
			return false;
	return true;
}

Player::Player()
{
}

Player::Player(int shipLimits[]){
	for (int i = 1; i < 11; i++)
		this->shipLimits[i] = shipLimits[i];
}


Player::~Player()
{
}

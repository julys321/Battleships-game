#include <iostream>
#include "Player.h"
#include "Ocean.h"
void drawPlayerOcean(Ocean ocean) {
	std::cout << "  0 1 2 3 4 5 6 7 8 9 \n";
		for (int y = 0; y < 10; y++) {
			std::cout << y << ' ';
			for (int x = 0; x < 10; x++) {
				if (ocean.getCellAtCoordinates(x, y) == Cell::INTACT_SHIP)
					std::cout << "# ";
				else if (ocean.getCellAtCoordinates(x, y) == Cell::MISSED_SHOT)
					std::cout << "O ";
				else if (ocean.getCellAtCoordinates(x, y) == Cell::SUNKEN_SHIP)
					std::cout << "X ";
				else if (ocean.getCellAtCoordinates(x, y) == Cell::WATER)
					std::cout << "  ";
			}
			std::cout << '\n';
		}
};
int main() {
	Player player;
	int userInput = 1;
	while (userInput != 0) {
		system("cls");
		drawPlayerOcean(player.ocean);
		std::cout << "What do you want to do? Place ship - 1 Stop playing - 0\n";
		std::cin >> userInput;
		if (userInput == 1) {
			int lengh, x, y, direction;
			std::cout << "Ship lengh\n";
			std::cin >> lengh;
			std::cout << "First ship cell coordinate x\n";
			std::cin >> x;
			std::cout << "First ship cell coordinate y\n";
			std::cin >> y;
			std::cout << "Direction East - 0 North - 1 South - 2 West - 3\n";
			std::cin >> direction;
			if (direction == 0)
				if (player.isShipAllowedToDeploy(lengh, x, y, Direction::EAST))
					player.deployShip(lengh, x, y, Direction::EAST);
				else {
					std::cout << "!!! Ship is not allowed to be placed there\n";
					system("pause");
				}
			if (direction == 1)
				if (player.isShipAllowedToDeploy(lengh, x, y, Direction::NORTH))
					player.deployShip(lengh, x, y, Direction::NORTH);
				else {
					std::cout << "!!! Ship is not allowed to be placed there\n";
					system("pause");
				}
			if (direction == 2)
				if (player.isShipAllowedToDeploy(lengh, x, y, Direction::SOUTH))
					player.deployShip(lengh, x, y, Direction::SOUTH);
				else {
					std::cout << "!!! Ship is not allowed to be placed there\n";
					system("pause");
				}
			if (direction == 3)
				if (player.isShipAllowedToDeploy(lengh, x, y, Direction::WEST))
					player.deployShip(lengh, x, y, Direction::WEST);
				else {
					std::cout << "!!! Ship is not allowed to be placed there\n";
					system("pause");
				}
		}
	}
}
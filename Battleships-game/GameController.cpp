#include "GameController.h"
#include <iostream>


void GameController::playTwoPlayers() {
	Player basePlayer;
	basePlayer.setShipLimit(1, 2);
	basePlayer.setShipLimit(2, 0);
	basePlayer.setShipLimit(3, 0);
	basePlayer.setShipLimit(4, 0);
	int lenght = 0, limit = 0;
	while (true) {
		system("cls");
		drawPlayerShipLimits(basePlayer);
		std::cout << "--------------SET-SHIP-LIMITS-------------------\n";
		std::cout << "----TO CANCEL: -1\n";
		std::cout << "Ship Lenght:\n";
		std::cin >> lenght;
		if (lenght == -1)
			break;
		std::cout << "Ship Limit:\n";
		std::cin >> limit;
		if (lenght == -1)
			break;
		basePlayer.setShipLimit(lenght,limit);

	}

	Player playerOne(basePlayer.shipLimits);
	Player playerTwo(basePlayer.shipLimits);

	std::cout << "Player One get ready to place ships!\n";
	system("pause");
	setupPlayerBoard(playerOne);
	system("cls");
	std::cout << "Player Two get ready to place ships!\n";
	system("pause");
	setupPlayerBoard(playerTwo);


	while (true) {

		if (playerOne.isSkippingATurn)
			playerOne.isSkippingATurn = 0;
		else {
			system("cls");
			std::cout << "Player One get ready to do a turn!\n";
			system("pause");
			doATurn(playerOne, playerTwo);
			system("pause");
			if (!playerTwo.areThereRemainingShips()) {
				system("cls");
				std::cout << "------------------------------------------------\n";
				std::cout << "------------------PLAYER-1-WINS-----------------\n";
				std::cout << "------------------------------------------------\n";
				drawPlayerEnemyOcean(playerOne.ocean, playerTwo.ocean);
				system("pause");
				break;
			}
		}
		if (playerTwo.isSkippingATurn)
			playerTwo.isSkippingATurn = 0;
		else {
			system("cls");
			std::cout << "Player Two get ready to do a turn!\n";
			system("pause");
			doATurn(playerTwo, playerOne);
			system("pause");
			if (!playerOne.areThereRemainingShips()) {
				system("cls");
				std::cout << "------------------------------------------------\n";
				std::cout << "------------------PLAYER-2-WINS-----------------\n";
				std::cout << "------------------------------------------------\n";
				drawPlayerEnemyOcean(playerTwo.ocean, playerOne.ocean);
				system("pause");
				break;
			}
		}
	}
}

void GameController::doATurn(Player &player, Player &enemy) {
	system("cls");
	drawPlayerEnemyOcean(player.ocean, enemy.ocean);
	makePlayerShoot(enemy);
	system("cls");
	drawPlayerEnemyOcean(player.ocean, enemy.ocean);
}

void GameController::setupPlayerBoard(Player &player) {
	while (!player.areAllShipLimitsExceeded()) {
		system("cls");
		makePlayerPlaceShip(player);
	}
}

void GameController::drawPlayerOcean(Ocean ocean) {
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
}

void GameController::drawPlayerShipLimits(Player &player) {
	std::cout << "----------------SHIP-LIMITS---------------\n";
	std::cout << "Lenght:  ";
	for (int i = 0; i < 11; i++)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "Limit:   ";
	for (int i = 0; i < 11; i++)
		std::cout << player.getShipLimit(i) << " ";
	std::cout << std::endl;
}

void GameController::makePlayerPlaceShip(Player & player) {
	int userInput = 1;
	drawPlayerOcean(player.ocean);
	drawPlayerShipLimits(player);
	std::cout << "----------------PLACE-SHIP----------------\n";
	int lengh, x, y, direction;
	std::cout << "Ship lengh:  ";
	std::cin >> lengh;
	std::cout << "First ship cell coordinate x:  ";
	std::cin >> x;
	std::cout << "First ship cell coordinate y:  ";
	std::cin >> y;
	std::cout << "Direction (East - 0 North - 1 South - 2 West - 3):  ";
	std::cin >> direction;
	if (direction == 0)
		if (player.isShipAllowedToDeploy(lengh, x, y, Direction::EAST))
			player.deployShip(lengh, x, y, Direction::EAST);
		else {
			std::cout << "\n!!!!!! Ship is not allowed to be placed there !!!!!\n";
			system("pause");
		}
	if (direction == 1)
		if (player.isShipAllowedToDeploy(lengh, x, y, Direction::NORTH))
			player.deployShip(lengh, x, y, Direction::NORTH);
		else {
			std::cout << "\n!!!!!! Ship is not allowed to be placed there !!!!!\n";
			system("pause");
		}
	if (direction == 2)
		if (player.isShipAllowedToDeploy(lengh, x, y, Direction::SOUTH))
			player.deployShip(lengh, x, y, Direction::SOUTH);
		else {
			std::cout << "\n!!!!!! Ship is not allowed to be placed there !!!!!\n";
			system("pause");
		}
	if (direction == 3)
		if (player.isShipAllowedToDeploy(lengh, x, y, Direction::WEST))
			player.deployShip(lengh, x, y, Direction::WEST);
		else {
			std::cout << "\n!!!!!! Ship is not allowed to be placed there !!!!!\n";
			system("pause");
		}
}

void GameController::drawPlayerEnemyOcean(Ocean ocean, Ocean enemyOcean) {
	std::cout << "-------YOUR-OCEAN-----|--|------ENEMY-OCEAN-----\n";
	std::cout << "  0 1 2 3 4 5 6 7 8 9 |--|  0 1 2 3 4 5 6 7 8 9 \n";
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
		std::cout << "|--|" << y << ' ';
		for (int x = 0; x < 10; x++) {
			if (enemyOcean.getCellAtCoordinates(x, y) == Cell::MISSED_SHOT)
				std::cout << "O ";
			else if (enemyOcean.getCellAtCoordinates(x, y) == Cell::SUNKEN_SHIP)
				std::cout << "X ";
			else
				std::cout << "  ";
		}
		std::cout << '\n';
	}
}

void GameController::makePlayerShoot(Player & enemy) {
	std::cout << "-------------------TAKE-A-SHOT-------------------\n";
	int x, y;
	std::cout << "X:  ";
	std::cin >> x;
	std::cout << "Y:  ";
	std::cin >> y;
	enemy.receiveShot(x, y);
}

GameController::GameController()
{
}


GameController::~GameController()
{
}

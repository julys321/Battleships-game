#pragma once
#include "Player.h"
class GameController
{
public:
	void playTwoPlayers(int shipLimits[]);
	void doATurn(Player &player,Player &enemy);
	void setupPlayerBoard(Player &player);
	void drawPlayerOcean(Ocean ocean);
	void drawPlayerShipLimits(Player & player);
	void makePlayerPlaceShip(Player &player);
	void drawPlayerEnemyOcean(Ocean ocean, Ocean enemyOcean);
	void makePlayerShoot(Player &enemy);
	GameController();
	~GameController();
};


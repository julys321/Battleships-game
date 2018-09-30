#pragma once
#include "Player.h"
class GameController
{
public:
	void playTwoPlayers();
	void doATurn(Player player);
	GameController();
	~GameController();
};


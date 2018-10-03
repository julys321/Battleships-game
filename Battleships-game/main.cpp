#include <iostream>
#include "GameController.h"

int main() {
	GameController gameController;
	int shipLimits[11]{ 0,1,0,0,0,0,0,0,0,0,0 };
	gameController.playTwoPlayers(shipLimits);
}
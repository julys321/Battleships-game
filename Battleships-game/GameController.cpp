#include "GameController.h"



void GameController::playTwoPlayers(){
	Player playerOne;
	Player playerTwo;
	while (!playerOne.isThereRemainingShips && !playerTwo.isThereRemainingShips) {
		doATurn(playerOne);
		doATurn(playerTwo);
	}
}

void GameController::doATurn(Player player){
}

GameController::GameController()
{
}


GameController::~GameController()
{
}

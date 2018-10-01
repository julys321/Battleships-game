#include "GameController.h"



void GameController::playTwoPlayers(){
	Player playerOne;
	Player playerTwo;
	while (playerOne.areThereRemainingShips() && playerTwo.areThereRemainingShips()) {
	//	doATurn(playerOne);
	//	doATurn(playerTwo);
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

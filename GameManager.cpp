#include "GameManager.h"

GameManager::GameManager(Player* player, GameDisplay* gameDisplay) {
	this->player = player;
	this->gameDisplay = gameDisplay;
}

void GameManager::Play() {
	// Play loop
}

void GameManager::Draw(Player* player) {
	int displayAddress = this->gameDisplay->getAddress();
	int* playerPixelArray = player->getPixelArray();
	for (size_t i = 0; i < 64; i++) {
		this->gameDisplay->getLedControl().setLed(displayAddress, playerPixelArray[i], playerPixelArray[i + 1], true);
	}
}

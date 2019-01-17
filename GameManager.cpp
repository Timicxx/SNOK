#include "GameManager.h"

GameManager::GameManager(int intensity)
	: gameDisplay(intensity), player(), inputManager(&this->player) {
}

void GameManager::Setup() {
	this->m_isPlaying = false;
	this->inputManager.Setup();
	Serial.begin(9600);
}

void GameManager::Draw() {
	int displayAddress = this->gameDisplay.getAddress();
	// int _X = this->player.getPositionX();
	// int _Y = this->player.getPositionY();
	
	byte positionArray[64];
	this->player.getPosition(positionArray);

	this->gameDisplay.getLedControl()->clearDisplay(displayAddress);
	for(int i = 0; i < 64; i += 2) {
		// Serial.println(positionArray[i]);
		if (positionArray[i] == 255) {
			break;
		}
		this->gameDisplay.getLedControl()->setLed(displayAddress, positionArray[i], positionArray[i + 1], true);
	}
	// this->gameDisplay.getLedControl()->setLed(displayAddress, _X, _Y, true);
}

bool GameManager::isPlaying() {
	return this->m_isPlaying;
}

void GameManager::isPlaying(bool state) {
	this->m_isPlaying = state;
}

Player* GameManager::getPlayer() {
	return &this->player;
}

GameDisplay* GameManager::getGameDisplay() {
	return &this->gameDisplay;
}

InputManager* GameManager::GetInputManager() {
	return &this->inputManager;
}
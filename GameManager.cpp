#include "GameManager.h"

GameManager::GameManager(int intensity, int* pos) 
	: gameDisplay(intensity), player(pos), inputManager(&this->player) {
}

void GameManager::Setup() {
	this->m_isPlaying = false;
	this->inputManager.Setup();
	this->player.setSize(this->gameDisplay.getSize());
	Serial.begin(9600);
}

void GameManager::Draw() {
	int displayAddress = this->gameDisplay.getAddress();
	int _X = this->player.getPositionX();
	int _Y = this->player.getPositionY();

	this->gameDisplay.getLedControl()->clearDisplay(displayAddress);
	this->gameDisplay.getLedControl()->setLed(displayAddress, _X, _Y, true);
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
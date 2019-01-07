#include "GameManager.h"

GameManager::GameManager(int din, int clk, int cs, int intensity, int tail, int score, int* pos) 
	: gameDisplay(din, clk, cs, intensity), player(tail, score, pos), inputManager(&this->player) {
}

void GameManager::Setup() {
	this->m_isPlaying = false;
}

void GameManager::Draw() {
	int displayAddress = this->gameDisplay.getAddress();
	this->gameDisplay.getLedControl()->clearDisplay(displayAddress);
	unsigned int* position = this->player.getPosition();
	this->gameDisplay.getLedControl()->setLed(displayAddress, position[0], position[1], true);
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
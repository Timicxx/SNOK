#include "InputManager.h"

InputManager::InputManager(Player* player) {
	this->player = player;
	this->resetDelta();
}

void InputManager::resetDelta() {
	this->currentTime = millis();
	this->previousTime = this->currentTime;
	this->deltaTime = 0;
}

void InputManager::checkForInput() {
	currentTime = millis();
	this->deltaTime = previousTime - currentTime;
	if (deltaTime > 0.5) {
		this->checkControls();
		previousTime = currentTime;
	}
}

void InputManager::checkControls() {
	// do input stuff
}
#include "Debugger.h"

Debugger::Debugger(GameManager* gameManager) {
	this->gameManager = gameManager;
	Serial.begin(9600);
}

void Debugger::debug() {
	
}

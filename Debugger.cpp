#include "Debugger.h"

Debugger::Debugger(GameManager* gameManager) {
	this->gameManager = gameManager;
}

void Debugger::Debug() {
	// Output player coordinates to serial console
	unsigned int* playerPos = gameManager->getPlayer()->getPosition();
	String output = "X: " + String(playerPos[0]) + " | " + "Y: " + String(playerPos[1]);
	Serial.println(output);
}

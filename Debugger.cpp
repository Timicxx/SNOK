#include "Debugger.h"

Debugger::Debugger(GameManager* gameManager) {
	this->gameManager = gameManager;
}

void Debugger::Debug() {
	// Output player coordinates to serial console
	int _X = gameManager->getPlayer()->getPositionX();
	int _Y = gameManager->getPlayer()->getPositionY();
	String output = "X: " + String(_X) + " | " + "Y: " + String(_Y);
	Serial.println(output);
}

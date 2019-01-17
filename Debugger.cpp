#include "Debugger.h"

Debugger::Debugger(GameManager* gameManager) {
	this->gameManager = gameManager;
}

void Debugger::Debug() {
	// Output player coordinates to serial console
	// int _X = gameManager->getPlayer()->getPositionX();
	// int _Y = gameManager->getPlayer()->getPositionY();
	// byte pos[64];
	// gameManager->getPlayer()->getPosition(pos);
	// int _X = pos[0];
	// int _Y = pos[1];
	// String output = "X: " + String(_X) + " | " + "Y: " + String(_Y);
	// Serial.println(output);
}

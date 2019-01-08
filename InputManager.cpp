#include "InputManager.h"

InputManager::InputManager(Player* player, int speed, int deadZone, int inputDelay, bool useSerialInput) {
	this->player = player;
	this->speed = speed;
	this->useSerialInput = useSerialInput;
	this->joystickVars->setDeadZone(deadZone);
	this->joystickVars->setInputDelay(inputDelay);
	this->joystickVars = new struct JoystickVars;
	this->serialVars = new struct SerialVars;
	this->resetDelta();
}

void InputManager::Setup() {
	pinMode(this->joystickVars->SWpin, INPUT);
	digitalWrite(this->joystickVars->SWpin, HIGH);
}

void InputManager::resetDelta() {
	this->currentTime = millis();
	this->previousTime = this->currentTime;
	this->deltaTime = 0;
}

void InputManager::checkForInput() {
	currentTime = millis();
	this->deltaTime = previousTime - currentTime;
	if (deltaTime > this->joystickVars->inputDelay) {
		switch (this->useSerialInput) {
			case(true):
				this->checkSerialInput();
				break;
			case(false):
				this->checkJoystickInput();
				break;
		}
		previousTime = currentTime;
	}
}

void InputManager::checkJoystickInput() {
	unsigned int Xaxis = analogRead(this->joystickVars->Xpin);
	unsigned int Yaxis = analogRead(this->joystickVars->Ypin);
	
	int incX = 0;
	int incY = 0;
	
	if(Xaxis >= this->joystickVars->centerJoystickValue * (1.0 + this->joystickVars->deadZone)) {
		incX = speed;
	} else if(Xaxis >= this->joystickVars->centerJoystickValue * this->joystickVars->deadZone) {
		incX = -speed;
	}
	
	if(Yaxis >= this->joystickVars->centerJoystickValue * (1.0 + this->joystickVars->deadZone)) {
		incY = speed;
	} else if(Yaxis >= this->joystickVars->centerJoystickValue * this->joystickVars->deadZone) {
		incY = -speed;
	}
	
	this->player->incPosition(incX, incY);
}

void InputManager::checkSerialInput() {
	int incX = 0;
	int incY = 0;

	if (Serial.available() > 0) {
		// Check if value from serial starts with x or y
	}
	this->player->incPosition(incX, incY);
}
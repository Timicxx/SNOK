#include "InputManager.h"

InputManager::InputManager(Player* player, int speed, float deadZone, float inputDelay, bool useSerialInput) {
	this->player = player;
	this->speed = speed;
	this->useSerialInput = useSerialInput;
	this->joystickVars = new struct JoystickVars;
	this->serialVars = new struct SerialVars;
	this->joystickVars->setDeadZone(deadZone);
	this->joystickVars->setInputDelay(inputDelay);
}

void InputManager::Setup() {
	pinMode(this->joystickVars->SWpin, INPUT);
	digitalWrite(this->joystickVars->SWpin, HIGH);
	this->resetDelta();
}

void InputManager::resetDelta() {
	this->previousTime = millis();
	this->deltaTime = 0.0;
}

void InputManager::checkForInput() {
	float currentTime = millis();
	this->deltaTime = currentTime - this->previousTime;
	if (this->deltaTime >= this->joystickVars->inputDelay) {
		if (this->useSerialInput) {
			this->checkSerialInput();
		} else {
			this->checkJoystickInput();
		}

		this->previousTime = currentTime;
	}
}

void InputManager::checkJoystickInput() {
	unsigned int Xaxis = analogRead(this->joystickVars->Xpin);
	unsigned int Yaxis = analogRead(this->joystickVars->Ypin);

	int incX = 0;
	int incY = 0;
	
	char direction = this->player->getDirection();
	
	if(Xaxis >= this->joystickVars->centerJoystickValue * (1.0 + this->joystickVars->deadZone)) {
		if(direction != 'W') {
			incX = -speed;
			direction = 'W';
		}
	} else if(Xaxis <= this->joystickVars->centerJoystickValue * this->joystickVars->deadZone) {
		if(direction != 'E') {
			incX = speed;
			direction = 'E';
		}
	}
	
	if(Yaxis >= this->joystickVars->centerJoystickValue * (1.0 + this->joystickVars->deadZone)) {
		if(direction != 'S') {
			incY = -speed;
			direction = 'S';
		}
	} else if(Yaxis <= this->joystickVars->centerJoystickValue * this->joystickVars->deadZone) {
		if(direction != 'N') {
			incY = speed;
			direction = 'N';
		}
	}
		
	this->player->setDirection(direction);
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
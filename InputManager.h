// InputManager.h

#ifndef _INPUTMANAGER_h
#define _INPUTMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Player.h"

class InputManager {
public:
	InputManager(Player* player, int speed=1, float deadZone=0.5, float inputDelay=300.0, bool useSerialInput=false);
	void checkForInput();
	void resetDelta();
	void Setup();
private:
	void checkJoystickInput();
	void checkSerialInput();
	Player* player;
	bool useSerialInput;
	float previousTime;
	float deltaTime;
	int speed;
	struct JoystickVars* joystickVars;
	struct SerialVars* serialVars;
};

struct JoystickVars {
public:
	const unsigned int centerJoystickValue = 512;
	const unsigned int SWpin = 2;
	const unsigned int Xpin = 0;
	const unsigned int Ypin = 1;
	float deadZone;
	float inputDelay;

	void setDeadZone(float deadZone) {
		this->deadZone = deadZone;
	}

	void setInputDelay(float inputDelay) {
		this->inputDelay = inputDelay;
	}
};

struct SerialVars {
public:
	const char Xaxis = 'x';
	const char Yaxis = 'y';
};

#endif


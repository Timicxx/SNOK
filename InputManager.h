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
	InputManager(Player* player);
	void checkForInput();
	void resetDelta();
private:
	void checkControls();
	Player* player;
	float currentTime;
	float previousTime;
	float deltaTime;
};

#endif

